#include "WindParticle.hpp"

#include "Random.hpp"

CWindParticle::CWindParticle(CExScene *scene, CCellAnim *cellAnim) {
    mParentScene = scene;
    mCellAnim = cellAnim;

    mCellAnim->setEnabled(false);

    mCellAnim->setLooping(true);
    mCellAnim->setSpeed(0.5 + sRandom.nextF32(0.5));

    mVelocityX = 0.0f;
    mSpeedY = 0.0f;

    mTargetVelocityX = 0.0f;
    mAccelX = 0.01f;

    mAreaWidth = 840.0f;
    mAreaHeight = 480.0f;

    mStopTimer = 0;
    mInvisibleTimer = -1;

    mNewAnimIndex = -1;

    mDisableWindResist = false;
}

CWindParticle::~CWindParticle(void) {}

void CWindParticle::fn_800C3168() {
    f32 newPosY = mCellAnim->getPosY() + mSpeedY;
    f32 newPosX = mCellAnim->getPosX() + mVelocityX;

    if (newPosY <= (mAreaHeight * 0.5f)) {
        if (newPosX >= -(mAreaWidth * 0.5f)) {
            if (newPosX > (mAreaWidth * 0.5f)) {
                newPosX -= mAreaWidth;
            }
        }
        else {
            newPosX += mAreaWidth;
        }
    }
    else {
        f32 randomPosX = sRandom.nextF32(mAreaWidth);

        newPosY -= mAreaHeight;
        newPosX = -((mAreaWidth * 0.5f) - randomPosX);

        if (!mDisableWindResist) {
            if (mTargetVelocityX <= 0.0f) {
                mVelocityX = -sRandom.nextF32(-mTargetVelocityX);
            }
            else {
                mVelocityX = sRandom.nextF32(mTargetVelocityX);
            }
        }

        if (mInvisibleTimer == 0) {
            mCellAnim->setEnabled(false);
        }
        else if (mNewAnimIndex != -1) {
            mCellAnim->fn_801DCE9C(mNewAnimIndex);
            mCellAnim->fn_801DCF18();
            mNewAnimIndex = -1;
        }
    }

    mCellAnim->setPos(newPosX, newPosY);

    if (mStopTimer < 1) {
        if (mVelocityX < mTargetVelocityX) {
            mVelocityX += mAccelX;
        }
        if (mTargetVelocityX < mVelocityX) {
            mVelocityX -= mAccelX;
        }
    }
    else {
        mStopTimer--;
    }

    if (mInvisibleTimer >= 0) {
        mInvisibleTimer--;
    }
}

void CWindParticle::fn_800C351C(void) {
    f32 x = sRandom.nextF32(mAreaWidth) - (mAreaWidth / 2);
    f32 y = sRandom.nextF32(mAreaHeight) - (mAreaHeight / 2);

    mCellAnim->setPos(x, y);
}

void CWindParticle::fn_800C366C(f32 targetVel, s32 stopTimer) {
    if (targetVel > 0.0f) {
        f32 rand = sRandom.nextF32(targetVel / 2);
        mTargetVelocityX =  (targetVel / 4) - (targetVel + rand);
    }
    else {
        f32 rand = sRandom.nextF32(-targetVel / 2);
        mTargetVelocityX =  (-targetVel / 4) - (targetVel - rand);
    }
    mStopTimer = stopTimer;
}

void CWindParticle::fn_800C3724(f32 accel) {
    mAccelX = accel;
}

void CWindParticle::fn_800C372C(s32 timer) {
    mInvisibleTimer = timer;
}

void CWindParticle::fn_800C3734(u16 animIdx, BOOL queue) {
    if (queue || !mCellAnim->getEnabled()) {
        mCellAnim->fn_801DCE9C(animIdx);
        mCellAnim->fn_801DCF18();
    }
    else {
        mNewAnimIndex = animIdx;
    }
}
