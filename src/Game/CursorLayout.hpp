#ifndef GAME_CURSORLAYOUT_HPP
#define GAME_CURSORLAYOUT_HPP

#include <revolution/types.h>

#include "Layout.hpp"

class CCursorLayout : public CLayout {
public:
    virtual ~CCursorLayout(void);
    virtual void _10(void);

    CCursorLayout(void) {
        setAnimationCount(0);
    }

private:
    u8 pad[0x3C - 0x1C]; // temp
};

#endif
