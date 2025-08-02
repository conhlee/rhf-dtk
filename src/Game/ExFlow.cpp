#include "ExFlow.hpp"

#include "Mem.hpp"

CExFlow::CExFlow(const TickFlowCode *code, f32 initRest) :
    CTickFlow(code, initRest)
{}

TICKFLOW_IMPL_CREATE_FN(CExFlow)

CExFlow::~CExFlow(void) {}

bool CExFlow::_1C(u32 opcode, u32 arg0, const s32 *args) {
    // TODO: implement
    return false;
}

void CExFlow::_14(void) {
    this->~CExFlow();
}
