#include "Strap/MyFlow.hpp"

#include "Strap/MyFlowDecl.hpp"

#include "Strap/MyChecker.hpp"

#include "InputCheckManager.hpp"
#include "InputChecker.hpp"

#include "Mem.hpp"

TICKFLOW_IMPL_CREATE_FN(Strap::CMyFlow)

Strap::CMyFlow::~CMyFlow(void) {}

bool Strap::CMyFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    switch (opcode) {
    case TF_STRAP_INPUT: {
        void *checkerAlloc = gInputCheckManager->fn_801E9144(sizeof(CMyChecker));
        CMyChecker *checker = new (checkerAlloc) CMyChecker;

        gInputCheckManager->fn_801E9158(checker, true);
    } break;
    
    default:
        return this->CExFlow::_1C(opcode, arg0, args);
    }

    return false;
}

void Strap::CMyFlow::_14(void) {
    this->~CMyFlow();
}
