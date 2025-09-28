#ifndef GAMEUTIL_LAYOUT_HPP
#define GAMEUTIL_LAYOUT_HPP

#include <revolution/types.h>

#include <nw4r/lyt.h>

#include "LayoutAnimation.hpp"

class CLayout {
public:
    virtual ~CLayout(void) {}
    virtual void _0C(void);
    virtual void _10(void) {
        fn_801D9B10();
    }
    virtual void _14(void);
    virtual void _18(nw4r::lyt::DrawInfo *);
    virtual void _1C(nw4r::lyt::DrawInfo *);
    virtual void _20(nw4r::lyt::DrawInfo *);

    CLayout(void);

    void fn_801D9B10(void);

    void fn_801D9E24(bool);

    nw4r::lyt::Layout *getLayout(void) {
        return mLayout;
    }
    CLayoutAnimation *getAnimation(u32 index) {
        return &mAnimations[index];
    }

    void buildLayout(const void *binAddr, nw4r::lyt::ResourceAccessor *resAccessor) {
        getLayout()->Build(binAddr, resAccessor);
    }
    void setAnimationCount(s32 count) {
        mAnimationCount = count;
    }

    bool getUpdateEnable(void) const { return mUpdateEnable; }
    void setUpdateEnable(bool enabled) { mUpdateEnable = enabled; }

    bool getDrawEnable(void) const { return mDrawEnable; }
    void setDrawEnable(bool enabled) { mDrawEnable = enabled; }

private:
    nw4r::lyt::Layout *mLayout;
    CLayoutAnimation *mAnimations; // CLayoutAnimation[mAnimationCount]
    s32 mAnimationCount;
    bool mUpdateEnable;
    bool mDrawEnable;
    bool mApplyManagerScale;
    f32 mScaleX;
    f32 mScaleY;
};

#endif