#ifndef GAMEUTIL_CELLANIM_HPP
#define GAMEUTIL_CELLANIM_HPP

#include <revolution/types.h>
#include <revolution/MTX.h>

#include <nw4r/math/types.h>

#include "List.hpp"

class CCellAnim : public CList {
public:
    typedef void (*CellAnimPrepFn)(CCellAnim *cell, u16 animID, u16 nextAnimID);

    CCellAnim *getNext(void) const {
        return static_cast<CCellAnim *>(this->CList::getNext());
    }
    CCellAnim *getPrev(void) const {
        return static_cast<CCellAnim *>(this->CList::getPrev());
    }

    u8 getID(void) const { return mID; }
    u16 getAnimID(void) const { return mAnimID; }

    f32 getFrame(void) const { return mFrame; }

    s32 getLayer(void) const { return mLayer; }

    f32 getSpeed(void) const { return mSpeed; }
    void setSpeed(f32 speed) { mSpeed = speed; }

    bool getTempoUpdate(void) const { return mTempoUpdate; }
    void setTempoUpdate(bool tempoUpdate) { mTempoUpdate = tempoUpdate; }

    u16 getTempo(void) const { return mTempo; }
    void setTempo(u16 tempo) { mTempo = tempo; }

    f32 getPosX(void) const { return mPos.x; }
    f32 getPosY(void) const { return mPos.y; }

    void setPosX(f32 x) { mPos.x = x; }
    void setPosY(f32 y) { mPos.y = y; }

    void setPos(f32 x, f32 y) { mPos = nw4r::math::VEC2(x, y); }

    f32 getAngle(void) const { return mAngle; }
    void setAngle(f32 angle) { mAngle = angle; }

    u8 getOpacity(void) const { return mOpacity; }
    void setOpacity(u8 opacity) { mOpacity = opacity; }

    bool getEnabled(void) const { return mEnabled; }
    void setEnabled(bool enabled) { mEnabled = enabled; }

    bool getPlaying(void) const { return mPlaying; }
    void setPlaying(bool playing) { mPlaying = playing; }

    bool getLooping(void) const { return mLooping; }
    void setLooping(bool looping) { mLooping = looping; }

    bool isReversed(void) const { return mBackward; }

    CCellAnim *getBaseCell(void) const { return mBaseCell; }

    CCellAnim *getBaseExtCellFirst(void) const { return mBaseExtCellFirst; }
    CCellAnim *getBaseExtCellNext(void) const { return mBaseExtCellNext; }

    void clearBase(void) {
        mBaseCell = NULL;
        mBaseExtCellNext = NULL;
        mBaseExtCell2 = NULL;
    }

    CCellAnim(void);
    ~CCellAnim(void);

    void init(u8 id, u16 animID);
    bool update(void);
    void makeMtx(BOOL defMtx, Mtx baseMtx);
    void draw(BOOL forceDraw);
    void setBase(CCellAnim *, u16, bool);

    void fn_801DCE9C(u16);
    void fn_801DCEE8(u16, CellAnimPrepFn);
    void fn_801DCF18(void);
    void fn_801DCF38(void);
    void fn_801DCF94(s32);
    void fn_801DD0AC(u16);
    void fn_801DD118(u16);
    void fn_801DD184(u16);
    void fn_801DD1F0(u16);
    void fn_801DD24C(u16, f32);
    void fn_801DD2B4(u16);
    u16 fn_801DD43C(void);

private:
    u8 mID;
    u16 mAnimID;
    u16 mPrepAnimID[8];
    u8 mPrepAnimCount;
    CellAnimPrepFn mPrepAnimCallback[8];
    f32 mFrame;
    s16 mTotalFrames;
    f32 mSpeed;
    u16 mTempo;
    Mtx mMtx;
    nw4r::math::VEC2 mPos;
    nw4r::math::VEC2 mSize;
    f32 mAngle;
    s32 mLayer;
    s32 mTexNumber;
    u8 mFgColorR, mFgColorG, mFgColorB;
    u8 mBgColorR, mBgColorG, mBgColorB;
    u8 mOpacity; // alpha
    bool mEnabled;
    bool mLinear;
    bool mPlaying;
    bool mLooping;
    bool mBackward;
    bool mDestroyAtEnd;
    bool mDisableAtEnd;
    bool mTempoUpdate;
    CCellAnim *mBaseCell;
    CCellAnim *mBaseExtCellFirst;
    CCellAnim *mBaseExtCellNext; // unsure
    CCellAnim *mBaseExtCell2; // unsure
    u16 mBasePartIndex;
    bool mBaseCellDraw;
};

#endif