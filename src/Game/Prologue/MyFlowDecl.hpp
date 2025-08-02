#ifndef GAME_PROLOGUE_MYFLOWDECL_HPP
#define GAME_PROLOGUE_MYFLOWDECL_HPP

#include <revolution/types.h>

#include "ExFlowDecl.hpp"

enum {
    /*   Prologue MyFlow opcodes (0x200)  */

    TF_PROLOGUE_START_ANIM = 0x200, ///< Start playing the prologue animation.
};

// command macros

#define TFC_PROLOGUE_START_ANIM() TFD_CMD(TF_PROLOGUE_START_ANIM, 0, 0),

#endif
