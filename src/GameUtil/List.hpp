#ifndef GAMEUTIL_LIST_HPP
#define GAMEUTIL_LIST_HPP

#include <revolution/types.h>

class CList {
public:
    virtual ~CList();
    virtual void finalInsert();
    virtual void finalDestroy();

    CList();

    // Insert the current list before the argument list
    void insertBefore(CList *);
    // Insert the current list after the argument list
    void insertAfter(CList *);
    void removeCurrent(void);
    void removeAll(void);

    CList *getNext(void) const {
        return mNext;
    }
    void setNext(CList *next) {
        mNext = next;
    }

    CList *getPrev(void) const {
        return mPrev;
    }
    void setPrev(CList *prev) {
        mPrev = prev;
    }

private:
    CList *mNext;
    CList *mPrev;
};

#endif