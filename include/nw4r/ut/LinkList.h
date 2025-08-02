#ifndef NW4R_UT_LINK_LIST
#define NW4R_UT_LINK_LIST

#include <revolution/types.h>
#include <nw4r/ut/inlines.h>

namespace nw4r {
namespace ut {

class LinkListNode : private NonCopyable {
public:
    LinkListNode() : mNext(0), mPrev(0) {

    }

    LinkListNode *GetNext() const {
        return mNext;
    }
    LinkListNode *GetPrev() const {
        return mPrev;
    }
    void SetNext(LinkListNode *node) {
        mNext = node;
    }
    void SetPrev(LinkListNode *node) {
        mPrev = node;
    }
private:

    LinkListNode *mNext;
    LinkListNode *mPrev;

};

namespace detail {
class LinkListImpl : private NonCopyable {
public:

    struct Iterator {
        Iterator(LinkListNode *node) : mPointer(node) {

        }

        LinkListNode *mPointer;
    };

    LinkListImpl() {
        Initialize_();
    }
    ~LinkListImpl();
    void Initialize_() {
        mSize = 0;
        LinkListNode *end = &mNode;
        mNode.SetNext(end);
        mNode.SetPrev(end);
    }
    int GetSize() const {
        return mSize;
    }
    bool IsEmpty() const {
        return mSize == 0;
    }
private:

    u32 mSize;
    LinkListNode mNode;
};
}

template <typename T, int I>
class LinkList : private detail::LinkListImpl {
public:

    LinkList() {

    }
    ~LinkList() {

    }

};

}
}

#endif
