#ifndef GAMEUTIL_DEBUGFONT_HPP
#define GAMEUTIL_DEBUGFONT_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CDebugFont : public TSingleton<CDebugFont> {
public:
    virtual void _10(void);

    CDebugFont();

private:
    u8 _pad[0x24 - 0x4];
};

extern CDebugFont *gDebugFont;

#endif
