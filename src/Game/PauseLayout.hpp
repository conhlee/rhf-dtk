#ifndef GAME_PAUSELAYOUT_HPP
#define GAME_PAUSELAYOUT_HPP

#include <revolution/types.h>

#include "Layout.hpp"

class CPauseLayout : public CLayout {
public:
    virtual ~CPauseLayout(void);
    virtual void _10(void);

    CPauseLayout(void) {
        setAnimationCount(3);
    }

    void setUnk1D(u8 unk) { mUnk1D = unk; }

private:
    u8 mUnk1C;
    u8 mUnk1D;
    u8 pad[0x2C - 0x1C - 2]; // temp
};

#endif
