#ifndef NW4R_LYT_LAYOUT_H
#define NW4R_LYT_LAYOUT_H

#include <revolution/types.h>
#include <revolution/MEM.h>
#include <nw4r/ut/LinkList.h>
#include <nw4r/ut/Rect.h>
#include <nw4r/ut/TagProcessor.h>
#include <nw4r/lyt/animation.h>
#include <nw4r/lyt/pane.h>
#include <nw4r/lyt/group.h>
#include <nw4r/lyt/arcResourceAccessor.h>

namespace nw4r {
namespace lyt {

// TODO: BAD!
class AnimResource;

class Layout {
public:
    Layout();
    virtual ~Layout();
    virtual bool Build(const void *, ResourceAccessor *);
    virtual AnimTransform *CreateAnimTransform();
    virtual AnimTransform *CreateAnimTransform(const void *, ResourceAccessor *);
    virtual AnimTransform *CreateAnimTransform(const AnimResource &, ResourceAccessor *);
    virtual void BindAnimation(AnimTransform *);
    virtual void UnbindAnimation(AnimTransform *);
    virtual void UnbindAllAnimation();
    virtual bool BindAnimationAuto(const AnimResource &, ResourceAccessor *);
    virtual void SetAnimationEnable(AnimTransform *, bool);
    virtual void CalculateMtx(const DrawInfo &);
    virtual void Draw(const DrawInfo &);
    virtual void Animate(unsigned long);
    virtual void SetTagProcessor(ut::WideTagProcessor* pProcessor);

    ut::Rect GetLayoutRect() const;
    Pane *GetRootPane() {
        return mpRootPane;
    }

    static MEMAllocator *GetAllocator() {
        return mspAllocator;
    }
    static void SetAllocator(MEMAllocator *pAllocator) {
        mspAllocator = pAllocator;
    }

protected:

    ut::LinkList<AnimTransform, offsetof(AnimTransform, mLink)> mAnimTransList;
    Pane *mpRootPane;
    GroupContainer *mpGroupContainer;
    Size mLayoutSize;

    static MEMAllocator *mspAllocator;
};

}
}

#endif
