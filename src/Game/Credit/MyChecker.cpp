#include "Credit/MyChecker.hpp"

u32 Credit::CMyChecker::_24(u32 a) {
    mScene->fn_800C4C70(a, 0);

    return 1;
}

u32 Credit::CMyChecker::_28(u32 a) {
    mScene->fn_800C4C70(a, 1);

    return 1;
}

u32 Credit::CMyChecker::_2C(void) {
    return 1;
}

u32 Credit::CMyChecker::_30(u32 a) {
    mScene->fn_800C4C70(a, 2);

    return 1;
}

Credit::CMyChecker::~CMyChecker(void) {}

void Credit::CMyChecker::_14(void) {
    this->~CMyChecker();
}

