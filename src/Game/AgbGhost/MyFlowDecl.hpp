#ifndef GAME_AGBGHOST_MYFLOWDECL_HPP
#define GAME_AGBGHOST_MYFLOWDECL_HPP

#include <revolution/types.h>

#include "ExFlowDecl.hpp"

enum {
    /*   AgbGhost MyFlow opcodes (0x200)  */

    TF_AGBGHOST_INPUT = 0x200,  ///< Register an input in 1 beat.
                                ///      - Args: leniancy: 0 for normal (-10, -6, 6, 10),
                                ///                        1 for relaxed (-14, -8, 8, 14),
                                ///                        2 for very relaxed (-18, -12, 12, 18),
                                ///                        3 for precise (-10, -4, 0, 0).
    TF_AGBGHOST_ARROW,          ///< Control the arrow.
                                ///      - Arg0: operation: 0 for readying the arrow,
                                ///                         1 for sliding it in from offscreen (args will be: start X position, time in ticks).
    TF_AGBGHOST_GHOST_ANIM,     ///< Control the ghost's animation.
                                ///      - Arg0: animation: 0 for step (args will be: position),
                                ///                         1 for timing instruction, 2 for dash.
    TF_AGBGHOST_DOOR_ANIM,      ///< Control the door's animation.
                                ///      - Arg0: animation: 0 for close.
    TF_AGBGHOST_204,            ///< TODO
    TF_AGBGHOST_205,            ///< TODO
};

// command macros



#endif
