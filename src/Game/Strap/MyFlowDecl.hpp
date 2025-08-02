#ifndef GAME_STRAP_MYFLOWDECL_HPP
#define GAME_STRAP_MYFLOWDECL_HPP

#include <revolution/types.h>

#include "ExFlowDecl.hpp"

enum {
    /*   Strap MyFlow opcodes (0x200)  */

    TF_STRAP_INPUT = 0x200, ///< Redundant.
};

// command macros

#define TFC_STRAP_INPUT() TFD_CMD(TF_STRAP_INPUT, 0, 0),

#endif
