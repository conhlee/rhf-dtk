#include "Strap/MyChecker.hpp"

u32 Strap::CMyChecker::_24(u32 a) {
    mScene->fn_8007B6C4(a, 0);

    return 1;
}

u32 Strap::CMyChecker::_28(u32 a) {
    mScene->fn_8007B6C4(a, 1);

    return 1;
}

u32 Strap::CMyChecker::_2C(void) {
    return 1;
}

u32 Strap::CMyChecker::_30(u32 a) {
    mScene->fn_8007B6C4(a, 2);

    return 1;
}

Strap::CMyChecker::~CMyChecker(void) {}

void Strap::CMyChecker::_14(void) {
    this->~CMyChecker();
}
