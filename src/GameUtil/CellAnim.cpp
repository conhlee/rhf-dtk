#include "CellAnimManager.hpp"
#include "Mem.hpp"
#include "TickFlowManager.hpp"

#include <revolution/GX.h>

CCellAnim::CCellAnim(void) {}
CCellAnim::~CCellAnim(void) {}

void CCellAnim::init(u8 id, u16 animID) {
    mID = id;
    mAnimID = animID;
    mPrepAnimCount = 0;
    mTotalFrames = gCellAnimManager->fn_801DBB58(this);
    mEnabled = true;
    mLinear = true;
    mPlaying = false;
    mFrame = 0.0f;
    mSpeed = 1.0f;
    mLooping = false;
    mBackward = false;
    mDestroyAtEnd = false;
    mDisableAtEnd = false;
    mTempoUpdate = false;
    mTempo = 120;
    mPos = nw4r::math::VEC2(0.0f, 0.0f);
    mSize = nw4r::math::VEC2(1.0f, 1.0f);
    mAngle = 0.0f;
    mLayer = 0;
    mTexNumber = -1;
    mFgColorR = 0;
    mFgColorG = 0;
    mFgColorB = 0;
    mBgColorR = 0xff;
    mBgColorG = 0xff;
    mBgColorB = 0xff;
    mOpacity = 0xff;
    setNext(NULL);
    setPrev(NULL);
    mBaseAnim = NULL;
    mBaseExtCellFirst = NULL;
    mBaseExtCellNext = NULL;
    mBaseExtCell2 = NULL;
    mBaseAnimDraw = false;
}

// Returns true if the cellanim needs to be destoryed afterwards
// regswap between totalFrames and nextAnimID (and inside the prep anim for-loop)
bool CCellAnim::update(void) {
    if (mPlaying) {
        if (mFrame < 0.0f) {
            mFrame = 0.0f;
        }
        else {
            f32 speed;
            if (mTempoUpdate) {
                f32 currTempo = gTickFlowManager->fn_801E2CA8();
                f32 cellTempo = mTempo;
                f32 d = (currTempo - cellTempo);
                if (((-2.0 < d) && (d < 2.0))) {
                    speed = mSpeed;
                }
                else {
                    speed = (mSpeed * currTempo) / cellTempo;
                }
            }
            else {
                speed = mSpeed;
            }

            f32 frame;
            if (gTickFlowManager->fn_801E4178()) {
                frame = mFrame + speed;
            }
            else {
                frame = mFrame + (60.0f / 50.0f) * speed; // (ntsc / pal)
            }

            mFrame = frame;
        }

        u16 totalFrames = mTotalFrames;
        while (mFrame >= totalFrames) {
            // handle overhead frames (only executed when animation has ended)
            if (mPrepAnimCount) {
                // prepared animations
                u16 prevAnimID = mAnimID;
                u16 nextAnimID = mPrepAnimID[0];
                if (mPrepAnimCallback[0]) {
                    mPrepAnimCallback[0](this, prevAnimID, nextAnimID);
                }
                mPrepAnimCount--;
                for (s32 i = 0; i < mPrepAnimCount; i++) {
                    mPrepAnimID[i + 0] = mPrepAnimID[i + 1];
                    mPrepAnimCallback[i + 0] = mPrepAnimCallback[i + 1];
                }
                mAnimID = nextAnimID;
                mTotalFrames = gCellAnimManager->fn_801DBB58(this);
                mPlaying = true;
                mFrame = -1.0f;
            }
            else {
                // finished all animations
                if (mLooping) {
                    mFrame -= totalFrames;
                    continue;
                }

                mPlaying = false;
                mFrame = totalFrames;

                if (mDestroyAtEnd) {
                    return true;
                }
                if (mDisableAtEnd) {
                    mEnabled = false;
                }

                break;
            }
        }
    }
    return false;
}

void CCellAnim::makeMtx(BOOL defMtx, Mtx baseMtx) {
    if (defMtx && mBaseAnim != NULL) {
        return;
    }

    CellAnimAnimationKey *key = gCellAnimManager->fn_801DBC7C(this);
    CellAnimSprite *sprite = gCellAnimManager->fn_801DBD38(this);

    Mtx transMtx;
    Mtx rotMtx;
    Mtx scaleMtx;
    Mtx tempMtx;

    if (defMtx) {
        MTXIdentity(mMtx);
    }
    else {
        MTXCopy(baseMtx, mMtx);
    }

    if ((mPos.x != 0.0) || (mPos.y != 0.0)) {
        MTXTrans(transMtx, mPos.x, mPos.y, 0.0f);
        MTXConcat(mMtx, transMtx, mMtx);
    }

    f64 myAngle = mAngle; // lmao
    if (myAngle != 0.0) {
        MTXRotDeg(rotMtx, 'z', mAngle);
        MTXConcat(mMtx, rotMtx, mMtx);
    }
    if ((mSize.x != 1.0) || (mSize.y != 1.0)) {
        MTXScale(scaleMtx, mSize.x, mSize.y, 1.0f);
        MTXConcat(mMtx, scaleMtx, mMtx);
    }

    if ((key->posX != 0.0) || (key->posY != 0.0)) {
        MTXTrans(transMtx, key->posX, key->posY, 0.0f);
        MTXConcat(mMtx, transMtx, mMtx);
    }
    if (key->angle != 0.0) {
        MTXRotDeg(rotMtx, 'z', key->angle);
        MTXConcat(mMtx, rotMtx, mMtx);
    }
    if ((key->scaleX != 1.0) || (key->scaleY != 1.0)) {
        MTXScale(scaleMtx, key->scaleX, key->scaleY, 1.0f);
        MTXConcat(mMtx, scaleMtx, mMtx);
    }

    if (mBaseExtCellFirst) {
        u16 texWidth = gCellAnimManager->fn_801DBE04(mID); // unused
        u16 texHeight = gCellAnimManager->fn_801DBE14(mID); // unused

        for (s32 i = 0; i < sprite->partCount; i++) {
            bool haseBaseExt = false;
            for (CCellAnim *cell = mBaseExtCellFirst; cell != NULL; cell = cell->mBaseExtCellNext) {
                if (i == cell->mBasePartIndex) {
                    haseBaseExt = true;
                    break;
                }
            }
            if (haseBaseExt) {
                CellAnimSpritePart* part = sprite->parts + i;

                f32 width = part->regionW * part->scaleX;
                f32 height = part->regionH * part->scaleY;

                f32 centerX = (width / 2.0f) + part->posX;
                f32 centerY = (height / 2.0f) + part->posY;

                if ((centerX != 0.0) || (centerY != 0.0)) {
                    MTXTrans(transMtx, centerX, centerY, 0.0f);
                    MTXConcat(mMtx, transMtx, tempMtx);
                }
                else {
                    MTXCopy(mMtx, tempMtx);
                }

                if (part->angle != 0.0) {
                    MTXRotDeg(rotMtx, 'z', part->angle);
                    MTXConcat(tempMtx, rotMtx, tempMtx);
                }
                if ((part->scaleX != 1.0) || (part->scaleY != 1.0)) {
                    MTXScale(scaleMtx, part->scaleX, part->scaleY, 1.0f);
                    MTXConcat(tempMtx, scaleMtx, tempMtx);
                }

                for (CCellAnim *anim = mBaseExtCellFirst; anim != NULL; anim = anim->mBaseExtCellNext) {
                    if (i == anim->mBasePartIndex) {
                        anim->makeMtx(false, tempMtx);
                    }
                }
            }
        }
    }
}

void CCellAnim::draw(BOOL forceDraw) {
    if (mBaseAnim == NULL || mBaseAnimDraw == false || forceDraw) {
        Mtx transMtx;
        Mtx rotMtx;
        Mtx scaleMtx;
        Mtx tempMtx;

        CellAnimAnimationKey *key = gCellAnimManager->fn_801DBC7C(this);
        CellAnimSprite *sprite = gCellAnimManager->fn_801DBD38(this);

        f32 texW = gCellAnimManager->fn_801DBE04(mID);
        f32 texH = gCellAnimManager->fn_801DBE14(mID);

        for (s32 i = 0; i < sprite->partCount; i++) {
            CellAnimSpritePart *part = sprite->parts + i;
            gCellAnimManager->fn_801DB3D8(mID, part, mLinear, mTexNumber);

            f32 sizeX = part->regionW * part->scaleX;
            f32 sizeY = part->regionH * part->scaleY;

            f32 centerX = (sizeX / 2.0f) + part->posX;
            f32 centerY = (sizeY / 2.0f) + part->posY;

            if ((centerX != 0.0) || (centerY != 0.0)) {
                MTXTrans(transMtx, centerX, centerY, 0.0f);
                MTXConcat(mMtx, transMtx, tempMtx);
            }
            else {
                MTXCopy(mMtx, tempMtx);
            }

            if (part->angle != 0.0) {
                MTXRotDeg(rotMtx, 'z', part->angle);
                MTXConcat(tempMtx, rotMtx, tempMtx);
            }

            if ((sizeX != 1.0) || (sizeY != 1.0)) {
                MTXScale(scaleMtx, sizeX, sizeY, 1.0);
                MTXConcat(tempMtx, scaleMtx, tempMtx);
            }

            GXLoadPosMtxImm(tempMtx, 0);

            u8 opacity = (key->opacity * part->opacity * mOpacity) / 255 / 255;
            GXSetTevColor(GX_TEVREG0, (GXColor){ mFgColorR, mFgColorG, mFgColorB, opacity });
            GXSetTevColor(GX_TEVREG1, (GXColor){ mBgColorR, mBgColorG, mBgColorB, opacity });

            f32 uvStartX = part->regionX / texW;
            f32 uvStartY = part->regionY / texH;
            f32 uvEndX = (part->regionX + part->regionW) / texW;
            f32 uvEndY = (part->regionY + part->regionH) / texH;

            if (part->flipX) {
                f32 temp = uvStartX;
                uvStartX = uvEndX;
                uvEndX = temp;
            }
            if (part->flipY) {
                f32 temp = uvStartY;
                uvStartY = uvEndY;
                uvEndY = temp;
            }

            GXBegin(GX_QUADS, GX_VTXFMT0, 4);

            GXPosition2f32(-0.5f, -0.5f);
            GXTexCoord2f32(uvStartX, uvStartY);

            GXPosition2f32(-0.5f, 0.5f);
            GXTexCoord2f32(uvStartX, uvEndY);

            GXPosition2f32(0.5f, 0.5f);
            GXTexCoord2f32(uvEndX, uvEndY);

            GXPosition2f32(0.5f, -0.5f);
            GXTexCoord2f32(uvEndX, uvStartY);

            GXEnd();

            for (CCellAnim *anim = mBaseExtCellFirst; anim != NULL; anim = anim->mBaseExtCellNext) {
                if (i == anim->mBasePartIndex && anim->mEnabled && anim->mBaseAnimDraw) {
                    anim->draw(true);
                }
            }
        }
    }
}
