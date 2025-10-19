#ifndef GAME_AGBTAP_MYFLOWDECL_HPP
#define GAME_AGBTAP_MYFLOWDECL_HPP

#include <revolution/types.h>

#include "ExFlowDecl.hpp"

// TODO: add naming, comments & macros ..

enum {
    /*   AgbTap MyFlow opcodes (0x200)  */

    TF_AGBTAP_INPUT = 0x200,
    TF_AGBTAP_BEAT_ANIM,
    TF_AGBTAP_SET_ANIME_MONKEY,
    TF_AGBTAP_SET_ANIME_GIRL,
    TF_AGBTAP_204,
    TF_AGBTAP_205,
    TF_AGBTAP_206,
    TF_AGBTAP_207
};

// command macros

#define TFC_AGBTAP_INPUT() TFD_CMD(TF_AGBTAP_INPUT, 0, 0),

#define TFC_AGBTAP_SET_ANIME_MONKEY(type) TFD_CMD(TF_AGBTAP_SET_ANIME_MONKEY, 1, 0), (TickFlowCode)(type),
#define TFC_AGBTAP_SET_ANIME_GIRL(type) TFD_CMD(TF_AGBTAP_SET_ANIME_GIRL, 1, 0), (TickFlowCode)(type),

#endif
