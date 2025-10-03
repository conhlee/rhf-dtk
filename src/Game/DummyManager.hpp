#ifndef GAME_DUMMYMANAGER_HPP
#define GAME_DUMMYMANAGER_HPP

#include "Singleton.hpp"

/*
    Never actually created / initialized but the game tries to destroy *a*
    manager instance at lbl_8032017C (gDummyManager), so we just interpret it
    as a CDummyManager * as a means to calling it's virtual dtor.
*/

class CDummyManager : public TSingleton<CDummyManager> {
public:
    virtual ~CDummyManager(void);

    CDummyManager(void) {}
};

extern CDummyManager *gDummyManager;

#endif
