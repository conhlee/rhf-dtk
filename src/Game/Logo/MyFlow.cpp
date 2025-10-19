#include "Logo/MyFlow.hpp"

#include "Logo/MyFlowDecl.hpp"

#include "Logo/MyChecker.hpp"

#include "InputCheckManager.hpp"
#include "InputChecker.hpp"

TICKFLOW_IMPL_CREATE_FN(Logo::CMyFlow)

Logo::CMyFlow::~CMyFlow(void) {}

bool Logo::CMyFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    switch (opcode) {
    case TF_LOGO_INPUT: {
        CMyChecker *checker = gInputCheckManager->makeNew<CMyChecker>();

        gInputCheckManager->fn_801E9158(checker, true);
    } break;
    
    default:
        return this->CExFlow::_1C(opcode, arg0, args);
    }

    return false;
}

void Logo::CMyFlow::_14(void) {
    this->~CMyFlow();
}

