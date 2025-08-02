#ifndef GAME_LOGO_MYFLOWDECL_HPP
#define GAME_LOGO_MYFLOWDECL_HPP

#include <revolution/types.h>

#include "ExFlowDecl.hpp"

enum {
    /*   Logo MyFlow opcodes (0x200)  */

    TF_LOGO_INPUT = 0x200,  ///< Redundant.
};

// command macros

#define TFC_LOGO_INPUT() TFD_CMD(TF_LOGO_INPUT, 0, 0),

#endif
