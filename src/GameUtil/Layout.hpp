#ifndef GAMEUTIL_CLAYOUT_HPP
#define GAMEUTIL_CLAYOUT_HPP

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

    CLayoutAnimation *getAnimations(void) {
        return mAnimations;
    }
    CLayoutAnimation *getAnimation(u32 index) {
        return &mAnimations[index];
    }

    void buildLayout(const void *buf, nw4r::lyt::ResourceAccessor *resAccessor) {
        getLayout()->Build(buf, resAccessor);
    }
    void setUnk0C(s32 arg0) {
        mAnimationCount = arg0;
    }
    u8 getUnk10(void) {
        return mUnk10;
    }

    u8 getUnk11(void) { return mUnk11; }
    void setUnk11(u8 unk) { mUnk11 = unk; }

private:
    nw4r::lyt::Layout *mLayout;
    CLayoutAnimation *mAnimations; // CLayoutAnimation[mAnimationCount]
    s32 mAnimationCount;
    u8 mUnk10;
    u8 mUnk11;
    u8 mUnk12;
    f32 mScaleX;
    f32 mScaleY;
};

#endif