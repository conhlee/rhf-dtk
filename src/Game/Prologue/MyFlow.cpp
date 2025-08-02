#include "Prologue/MyFlow.hpp"

#include "Prologue/MyFlowDecl.hpp"

#include "Prologue/MyLayout.hpp"

#include "LayoutManager.hpp"

#include "Mem.hpp"

TICKFLOW_IMPL_CREATE_FN(Prologue::CMyFlow)

Prologue::CMyFlow::~CMyFlow(void) {}

bool Prologue::CMyFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    switch (opcode) {
    case TF_PROLOGUE_START_ANIM: {
        CMyLayout *layout = static_cast<CMyLayout *>(gLayoutManager->fn_801D6C50(0));
        layout->fn_8007785C(args[0]);
    } break;
    
    default:
        return this->CExFlow::_1C(opcode, arg0, args);
    }

    return false;
}

void Prologue::CMyFlow::_14(void) {
    this->~CMyFlow();
}
