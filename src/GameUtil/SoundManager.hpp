#ifndef GAMEUTIL_CSOUNDMANAGER_HPP
#define GAMEUTIL_CSOUNDMANAGER_HPP

#include <revolution/types.h>
#include "Singleton.hpp"

#include "SNDHandle.hpp"

class CSoundManager : public TSingleton<CSoundManager> {
public:
    CSoundManager();

    void fn_801E4D60();
    void fn_801E4F60(u32, f32 = .0f, SNDHandle * = NULL);
    void fn_801E62B8(u32, SNDHandle *);
    void fn_801E65F4(f32, s32 = 0, SNDHandle * = NULL);
    void fn_801E6ECC(f32);
    bool fn_801E7334(void);
    void *fn_801E73D4(u32);
    f32 fn_801E74EC(void *);
    f32 fn_801E75C0(u32);

    static bool fn_801E4D4C(void);
    static void fn_801E4D54(void);
};

extern CSoundManager *gSoundManager;

#endif