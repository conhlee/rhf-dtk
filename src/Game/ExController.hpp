#ifndef GAME_EXCONTROLLER_HPP
#define GAME_EXCONTROLLER_HPP

#include <revolution/types.h>

#include "Controller.hpp"

class CExController : public CController {
public:
    CExController(s32 index);

    static CController *create(s32 index) {
        return static_cast<CController *>(new CExController(index));
    }

private:
    char _pad[0x52f8 - 0x13b8];
};

#endif