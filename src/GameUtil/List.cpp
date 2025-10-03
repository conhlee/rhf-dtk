#include "List.hpp"

void CList::finalDestroy(void) {}
void CList::finalInsert(void) {}

CList::CList(void) {
    mNext = NULL;
    mPrev = NULL;
}
CList::~CList(void) {}

void CList::insertBefore(CList *list) {
    mNext = list;
    mPrev = (list != NULL) ? list->mPrev : NULL;

    if (mNext != NULL) {
        mNext->mPrev = this;
    }
    if (mPrev != NULL) {
        mPrev->mNext = this;
    }
    finalInsert();
}

void CList::insertAfter(CList *list) {
    mNext = (list != NULL) ? list->mNext : NULL;
    mPrev = list;

    if (mNext != NULL) {
        mNext->mPrev = this;
    }
    if (mPrev != NULL) {
        mPrev->mNext = this;
    }
    finalInsert();
}

void CList::removeCurrent(void) {
    if (mNext != NULL) {
        mNext->mPrev = mPrev;
    }
    if (mPrev != NULL) {
        mPrev->mNext = mNext;
    }

    mNext = NULL;
    mPrev = NULL;
    finalDestroy();
}

void CList::removeAll(void) {
    CList *current = this;
    CList *next;

    while (current != NULL) {
        next = current->mNext;

        if (next != NULL) {
            next->mPrev = current->mPrev;
        }
        if (current->mPrev != NULL) {
            current->mPrev->mNext = current->mNext;
        }

        current->mNext = NULL;
        current->mPrev = NULL;
        current->finalDestroy();

        current = next;
    }
}
