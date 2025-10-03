#ifndef GAME_CAFETOPIC_HPP
#define GAME_CAFETOPIC_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CCafeTopic : public TSingleton<CCafeTopic> {
public:
    CCafeTopic(void) {}

    void fn_8009CE34(void);

private:
    u8 _pad[0x14 - 0x4];
};

extern CCafeTopic *gCafeTopic;

#endif
