#ifndef GAMEUTIL_DEBUGCONSOLE_HPP
#define GAMEUTIL_DEBUGCONSOLE_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CDebugConsole : public TSingleton<CDebugConsole> {
public:
    virtual void _10(s32);

    CDebugConsole();

private:
    u8 _pad[0x10 - 0x4];
};

extern CDebugConsole *gDebugConsole;

#endif
