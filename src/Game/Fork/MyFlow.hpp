#ifndef GAME_FORK_MYFLOW_HPP
#define GAME_FORK_MYFLOW_HPP

#include <revolution/types.h>

#include "ExFlow.hpp"

#include "Fork/SceneFork.hpp"

#include "GameManager.hpp"

namespace Fork {

class CMyFlow : public CExFlow {
public:
    virtual ~CMyFlow(void);
    virtual void _14(void);
    virtual bool _1C(u32 opcode, u32 arg0, const s32 *args);

    CMyFlow(const TickFlowCode *code, f32 initRest) :
        CExFlow(code, initRest)
    {
        mScene = gGameManager->getCurrentScene<CSceneFork>();
    }

    TICKFLOW_DECL_CREATE_FN()

private:
    CSceneFork *mScene;
};

} // namespace Fork

#endif
