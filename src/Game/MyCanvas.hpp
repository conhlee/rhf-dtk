#ifndef GAME_MYCANVAS_HPP
#define GAME_MYCANVAS_HPP

#include <revolution/types.h>

#include "CellAnim.hpp"

#include "TimeRatio.hpp"

#include "Singleton.hpp"

#include <nw4r/math/types.h>

class CMyCanvasManager; // Forward-declaration

class CMyCanvas {
    friend class CMyCanvasManager;

public:
    virtual ~CMyCanvas(void);

    CMyCanvas();

    void setScale(f32 x, f32 y) {
        mBaseAnim->setScale(x, y);
        mTRScaleX.setIsTicking(false);
        mTRScaleY.setIsTicking(false);
    }
    void setOffset(f32 x, f32 y) {
        mBaseAnim->setPos(x, y);
        mTROffsetX.setIsTicking(false);
        mTROffsetY.setIsTicking(false);
    }
    void setAngle(f32 angle) {
        mBaseAnim->setAngle(angle);
        mTRAngle.setIsTicking(false);
    }

    void setScaleTimed(s32 easingType, s32 easingPower, f32 time, f32 x, f32 y) {
        mTRScaleX.setEasing(easingType, easingPower);
        mTRScaleX.fn_801EA698(mBaseAnim->getScaleX(), x);
        mTRScaleX.fn_801EA550(0.0f, time, true);

        mTRScaleY.setEasing(easingType, easingPower);
        mTRScaleY.fn_801EA698(mBaseAnim->getScaleY(), y);
        mTRScaleY.fn_801EA550(0.0f, time, true);
    }
    void setOffsetTimed(s32 easingType, s32 easingPower, f32 time, f32 x, f32 y) {
        mTROffsetX.setEasing(easingType, easingPower);
        mTROffsetX.fn_801EA698(mBaseAnim->getPosX(), x);
        mTROffsetX.fn_801EA550(0.0f, time, true);

        mTROffsetY.setEasing(easingType, easingPower);
        mTROffsetY.fn_801EA698(mBaseAnim->getPosY(), y);
        mTROffsetY.fn_801EA550(0.0f, time, true);
    }
    void setAngleTimed(s32 easingType, s32 easingPower, f32 time, f32 angle) {
        mTRAngle.setEasing(easingType, easingPower);
        mTRAngle.fn_801EA698(mBaseAnim->getAngle(), angle);
        mTRAngle.fn_801EA550(0.0f, time, true);
    }

    void scaleTimingEnd(void) {
        mTRScaleX.setIsTicking(false);
        mTRScaleY.setIsTicking(false);
    }
    void offsetTimingEnd(void) {
        mTROffsetX.setIsTicking(false);
        mTROffsetY.setIsTicking(false);
    }
    void angleTimingEnd(void) {
        mTRAngle.setIsTicking(false);
    }

    void updateTiming(void) {
        if (mTRScaleX.getIsTicking()) {
            mTRScaleX.fn_801E9DE8(FALSE);
            mTRScaleY.fn_801E9DE8(FALSE);

            mBaseAnim->setScale(mTRScaleX.getCurrent(), mTRScaleY.getCurrent());
        }
        if (mTROffsetX.getIsTicking()) {
            mTROffsetX.fn_801E9DE8(FALSE);
            mTROffsetY.fn_801E9DE8(FALSE);

            mBaseAnim->setPos(mTROffsetX.getCurrent(), mTROffsetY.getCurrent());
        }
        if (mTRAngle.getIsTicking()) {
            mTRAngle.fn_801E9DE8(FALSE);

            mBaseAnim->setAngle(mTRAngle.getCurrent());
        }
    }

    void setDefault(void) {
        setScale(1.0f, 1.0f);
        setOffset(0.0f, 0.0f);
        setAngle(0.0f);
    }

    void setBaseAnim(CCellAnim *anim) { mBaseAnim = anim; }
    CCellAnim *getBaseAnim(void) const { return mBaseAnim; }

private:
    CCellAnim *mBaseAnim;
    CTRFloat mTRScaleX, mTRScaleY;
    CTRFloat mTROffsetX, mTROffsetY;
    CTRFloat mTRAngle;
};

class CMyCanvasManager : public TSingleton<CMyCanvasManager> {
public:
    virtual ~CMyCanvasManager(void);

    CMyCanvasManager(void);

    void fn_8007BC9C(void);
    void fn_8007BDAC(s32 index);
    void fn_8007BE0C(void);
    void fn_8007BEA0(void);
    void fn_8007BEF8(s32 index);
    s32 fn_8007BF28(void);
    void fn_8007BF30(CCellAnim *anim, s32 index);
    void fn_8007BF6C(s32 index, f32 x, f32 y);
    void fn_8007BFA8(s32 index, f32 x, f32 y);
    void fn_8007BFE4(s32 index, f32 angle);
    void fn_8007C000(s32 index, s32 easeType, s32 easePow, f32 time, f32 x, f32 y);
    void fn_8007C0C8(s32 index, s32 easeType, s32 easePow, f32 time, f32 x, f32 y);
    void fn_8007C190(s32 index, s32 easeType, s32 easePow, f32 time, f32 angle);
    void fn_8007C200(s32 index);
    void fn_8007C218(s32 index);
    void fn_8007C230(s32 index);
    nw4r::math::VEC2 fn_8007C244(s32 index);
    nw4r::math::VEC2 fn_8007C25C(s32 index);
    f32 fn_8007C274(s32 index);

private:
    static void fn_8007B95C(void);

    void updateAllTiming(void) {
        for (s32 i = 0; i < CANVAS_COUNT; i++) {
            mCanvas[i].updateTiming();
        }
    }

public:
    enum { CANVAS_COUNT = 10 };

private:
    CMyCanvas mCanvas[CANVAS_COUNT];
    s32 mCanvasIndex;
};

extern CMyCanvasManager *gMyCanvasManager;

#endif