#ifndef GAME_PLAYHISTORY_HPP
#define GAME_PLAYHISTORY_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CPlayHistory : public TSingleton<CPlayHistory> {
public:
    CPlayHistory(void) {}

    void fn_8009A704(void);

private:
    u8 _pad[0x44 - 0x4];
};

extern CPlayHistory *gPlayHistory;

#endif
