#include "MyCanvas.hpp"

#include "CellAnimManager.hpp"

#include "cellanim/permanent/rcad_permanent_labels.h"

void CMyCanvasManager::fn_8007B95C(void) {
    gMyCanvasManager->updateAllTiming();
}

CMyCanvas::CMyCanvas(void) {
    mBaseAnim = NULL;
}

CMyCanvas::~CMyCanvas(void) {}

CMyCanvasManager::CMyCanvasManager(void) {}

CMyCanvasManager::~CMyCanvasManager(void) {}

void CMyCanvasManager::fn_8007BC9C(void) {
    for (s32 i = 0; i < CANVAS_COUNT; i++) {
        CCellAnim *baseAnim = gCellAnimManager->fn_801DBE7C(0xFF, permanent_canvas);
        mCanvas[i].setBaseAnim(baseAnim);

        fn_8007BDAC(i);

        if (i > 0) {
            baseAnim->setBase(mCanvas[i - 1].getBaseAnim(), 0, false);
        }
    }

    mCanvasIndex = -1;

    gCellAnimManager->fn_801DC164(NULL);
    gCellAnimManager->fn_801DC174(fn_8007B95C);
}

void CMyCanvasManager::fn_8007BDAC(s32 index) {
    mCanvas[index].setDefault();
}

void CMyCanvasManager::fn_8007BE0C(void) {
    for (s32 i = 0; i < CANVAS_COUNT; i++) {
        mCanvas[i].setDefault();
    }
}

void CMyCanvasManager::fn_8007BEA0(void) {
    for (s32 i = 0; i < CANVAS_COUNT; i++) {
        CCellAnim *baseAnim = mCanvas[i].getBaseAnim();
        if (baseAnim != NULL) {
            gCellAnimManager->fn_801DBFA0(baseAnim);
        }
    }
}

void CMyCanvasManager::fn_8007BEF8(s32 index) {
    mCanvasIndex = index;
    if (index < 0) {
        gCellAnimManager->fn_801DC164(NULL);
    }
    else {
        gCellAnimManager->fn_801DC164(mCanvas[index].getBaseAnim());
    }
}

s32 CMyCanvasManager::fn_8007BF28(void) {
    return mCanvasIndex;
}

void CMyCanvasManager::fn_8007BF30(CCellAnim *anim, s32 index) {
    if (index < 0) {
        anim->setBase(NULL, 0, false);
    }
    else {
        anim->setBase(mCanvas[index].getBaseAnim(), 0, false);
    }
}

void CMyCanvasManager::fn_8007BF6C(s32 index, f32 x, f32 y) {
    mCanvas[index].setScale(x, y);
}

void CMyCanvasManager::fn_8007BFA8(s32 index, f32 x, f32 y) {
    mCanvas[index].setOffset(x, y);
}

void CMyCanvasManager::fn_8007BFE4(s32 index, f32 angle) {
    mCanvas[index].setAngle(angle);
}

void CMyCanvasManager::fn_8007C000(s32 index, s32 easeType, s32 easePow, f32 time, f32 x, f32 y) {
    mCanvas[index].setScaleTimed(easeType, easePow, time, x, y);
}

void CMyCanvasManager::fn_8007C0C8(s32 index, s32 easeType, s32 easePow, f32 time, f32 x, f32 y) {
    mCanvas[index].setOffsetTimed(easeType, easePow, time, x, y);
}

void CMyCanvasManager::fn_8007C190(s32 index, s32 easeType, s32 easePow, f32 time, f32 angle) {
    mCanvas[index].setAngleTimed(easeType, easePow, time, angle);
}

void CMyCanvasManager::fn_8007C200(s32 index) {
    mCanvas[index].scaleTimingEnd();
}
void CMyCanvasManager::fn_8007C218(s32 index) {
    mCanvas[index].offsetTimingEnd();
}
void CMyCanvasManager::fn_8007C230(s32 index) {
    mCanvas[index].angleTimingEnd();
}

nw4r::math::VEC2 CMyCanvasManager::fn_8007C244(s32 index) {
    return mCanvas[index].getBaseAnim()->getScale();
}

nw4r::math::VEC2 CMyCanvasManager::fn_8007C25C(s32 index) {
    return mCanvas[index].getBaseAnim()->getPos();
}

f32 CMyCanvasManager::fn_8007C274(s32 index) {
    return mCanvas[index].getBaseAnim()->getAngle();
}
