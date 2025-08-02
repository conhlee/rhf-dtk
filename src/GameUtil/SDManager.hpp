#ifndef GAMEUTIL_CSDMANAGER_HPP 
#define GAMEUTIL_CSDMANAGER_HPP

#include <revolution/types.h>
#include "Singleton.hpp"

class CSDManager : public TSingleton<CSDManager> {
public:
    virtual void _08(void);
    virtual ~CSDManager(void);
    virtual void _10(void);
    virtual void _14(void);

    CSDManager(void);

    u32 fn_801EC3A8(const char *str);

private:
    u8 pad04[0x11a0-4];
};

extern CSDManager *gSDManager;

#endif