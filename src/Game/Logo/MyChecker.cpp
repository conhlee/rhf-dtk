#include "Logo/MyChecker.hpp"

u32 Logo::CMyChecker::_24(u32 a) {
    mScene->fn_800A0D64(a, 0);

    return 1;
}

u32 Logo::CMyChecker::_28(u32 a) {
    mScene->fn_800A0D64(a, 1);

    return 1;
}

u32 Logo::CMyChecker::_2C(void) {
    return 1;
}

u32 Logo::CMyChecker::_30(u32 a) {
    mScene->fn_800A0D64(a, 2);

    return 1;
}

Logo::CMyChecker::~CMyChecker(void) {}

void Logo::CMyChecker::_14(void) {
    this->~CMyChecker();
}

