#ifndef GAME_AGBTAP_MYFLOW_HPP
#define GAME_AGBTAP_MYFLOW_HPP

#include <revolution/types.h>

#include "ExFlow.hpp"

#include "AgbTap/SceneAgbTap.hpp"

#include "GameManager.hpp"

namespace AgbTap {

class CMyFlow : public CExFlow {
public:
    virtual ~CMyFlow(void);
    virtual void _14(void);
    virtual bool _1C(u32 opcode, u32 arg0, const s32 *args);

    CMyFlow(const TickFlowCode *code, f32 initRest) :
        CExFlow(code, initRest)
    {
        mScene = gGameManager->getCurrentScene<CSceneAgbTap>();
    }

    TICKFLOW_DECL_CREATE_FN()

private:
    CSceneAgbTap *mScene;
};

} // namespace AgbTap

#endif
