#ifndef GAME_SAVEDATA_HPP
#define GAME_SAVEDATA_HPP

#include <revolution/types.h>
#include "Singleton.hpp"

struct SaveDataFile {
    u8 pad00[0x280];

    void fn_80077C0C(s8);

    s8 fn_80077DF8(void);
    u8 fn_80077E08(void);
    void fn_800786E4(void);
};

class CSaveData : public TSingleton<CSaveData> {
public:
    virtual void _08(void);
    virtual ~CSaveData(void);

    CSaveData();

    void fn_80078E04(void);
    void fn_80078E8C(void);

    SaveDataFile *fn_80078F4C(void);
    void fn_80078F68(void);

private:
    char _pad[0x1448 - 0x4];
};

extern CSaveData *gSaveData;

#endif
