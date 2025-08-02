#ifndef GAME_STRAP_MYCHECKER_HPP
#define GAME_STRAP_MYCHECKER_HPP

#include <revolution/types.h>

#include "ExChecker.hpp"

#include "Strap/SceneStrap.hpp"

#include "GameManager.hpp"

namespace Strap {

class CMyChecker : public CExChecker {
public:
    virtual ~CMyChecker(void);
    virtual void _14(void);
    virtual u32 _24(u32);
    virtual u32 _28(u32);
    virtual u32 _2C(void);
    virtual u32 _30(u32);

    CMyChecker(void) {
        mScene = static_cast<CSceneStrap *>(gGameManager->getCurrentScene());
    }

private:
    CSceneStrap *mScene;
};

}

#endif
