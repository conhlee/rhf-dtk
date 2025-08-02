#include "AgbGhost/MyFlow.hpp"

#include "AgbGhost/MyFlowDecl.hpp"

#include "AgbGhost/MyChecker.hpp"

#include "InputCheckManager.hpp"
#include "InputChecker.hpp"

#include "TickFlowManager.hpp"

TICKFLOW_IMPL_CREATE_FN(AgbGhost::CMyFlow)

AgbGhost::CMyFlow::~CMyFlow(void) {}

bool AgbGhost::CMyFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    switch (opcode) {
    case TF_AGBGHOST_INPUT: {
        void *checkerAlloc = gInputCheckManager->fn_801E9144(sizeof(CMyChecker));
        CMyChecker *checker = new (checkerAlloc) CMyChecker;

        checker->fn_801E7D5C(4);

        switch (args[0]) {
        case 0:
            checker->fn_801E7DBC(48.0f, -10.0f, -6.0f, 6.0f, 10.0f);
            break;
        case 1:
            checker->fn_801E7DBC(48.0f, -14.0f, -8.0f, 8.0f, 14.0f);
            break;
        case 2:
            checker->fn_801E7DBC(48.0f, -18.0f, -12.0f, 12.0f, 18.0f);
            break;
        case 3:
            checker->fn_801E7DBC(48.0f, -10.0f, -4.0f, 0.0f, 0.0f);
            break;
        default:
            break;
        }

        gInputCheckManager->fn_801E9158(checker, true);
    } break;

    case TF_AGBGHOST_ARROW: {
        if (arg0 == 0) {
            mScene->fn_800A8080();
        }
        else if (arg0 == 1) {
            mScene->fn_800A80EC(args[0], args[1]);
        }
    } break;

    case TF_AGBGHOST_GHOST_ANIM: {
        if (arg0 == 0) {
            mScene->fn_800A81A8(args[0]);
        }
        else if (arg0 == 1) {
            mScene->fn_800A860C();
        }
        else if (arg0 == 2) {
            mScene->fn_800A8658();
        }
    } break;

    case TF_AGBGHOST_DOOR_ANIM: {
        if (arg0 == 0) {
            mScene->fn_800A8730();
        }
    } break;

    case TF_AGBGHOST_204: {
        mScene->mGhostHeight = args[0];

        if (gTickFlowManager->getUnk1C() == 3) {
            gTickFlowManager->fn_801E3E2C(mScene->mGhostHeight / 256.0f, 15);
        }
        mScene->mUnk1B2 = true;
    } break;

    case TF_AGBGHOST_205: {
        if (arg0 == 0) {
            mScene->mUnk19C.Pause(args[0], 30);
        }
        else if (arg0 == 1) {
            mScene->fn_800A8788(args[0]);
        }
        else if (arg0 == 2) {
            mScene->mUnk1B1 = args[0];
        }
    } break;
    
    default:
        return this->CExFlow::_1C(opcode, arg0, args);
    }

    return false;
}

void AgbGhost::CMyFlow::_14(void) {
    this->~CMyFlow();
}
