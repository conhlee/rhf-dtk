#ifndef GAMEUTIL_DEBUGPRINT_HPP
#define GAMEUTIL_DEBUGPRINT_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CDebugPrint : public TSingleton<CDebugPrint> {
public:
    virtual void _08(void);
    virtual ~CDebugPrint(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);

    CDebugPrint(void);

    void fn_801EC674(s32 x, s32 y, s32 frames, const char *fmt, ...);

private:
    u8 mUnk04[0x34 - 4];
};

extern CDebugPrint *gDebugPrint;

#endif 