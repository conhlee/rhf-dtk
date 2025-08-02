#ifndef GAME_EXFLOWDECL_HPP
#define GAME_EXFLOWDECL_HPP

#include <revolution/types.h>

#include "TickFlowDecl.hpp"

enum {
    /*   ExFlow opcodes (0x100 to 0x141)  */

    TF_SET_SCENE = 0x100,       ///< Set the current scene. Args: scene ID, tickflow *
    TF_SET_SCENE_VER,           ///< Set a scene's version. Args: scene ID, version
    TF_SCENE_DATA,              ///< (Un)load a scene's data (cellanim data & layouts). Arg0: 0 for load, 1 for unload; Args: scene ID
    TF_103,
    TF_104,
    TF_SET_PROLOGUE,            ///< Set the prologue. Arg0: is 2P; Args: name, version
    TF_SET_EPILOGUE,            ///< Set the epilogue. Args: name, version
    TF_SET_EPILOGUE_MSG,        ///< Set a epilogue message. Arg0: type: 0 for OK, 1 for Try Again, 2 for Superb; Args: mesg ID string
    TF_SET_GRADING_CAPTION,     ///< Set the grading caption. Args: mesg ID string
    TF_109,
    TF_FADE,                    ///< Fade the screen in/out. Arg0: 0 for fade out, 1 for fade in; Args: time is in frames, time (in ticks or frames).
    TF_10B,
    TF_UI_SKIP_POS,             ///< Set the "(-) Skip" graphic's position.
                                ///      - Arg0: position: 0 for top-left, 1 for top-right,
                                ///                        2 for bottom-left, 3 for bottom-right.
    TF_UI_SKIP_ANIM,            ///< Play the "(-) Skip" graphic's animation. Args: is practice
    TF_UI_PAUSE,                ///< Show/hide the "(+) Pause" graphic. Arg0: 0 for show, 1 for hide
    TF_10F,
    TF_110,
    TF_111,
    TF_MASK01_VISIBLE,          ///< Set mask01's visibility. Args: 0 for invisible, 1 for visible 
    TF_MASK01_OPACITY,          ///< Set mask01's opacity. Args: opacity (0-255)
    TF_MASK01_COLOR,            ///< Set mask01's color. Args: color R (0-255), color G (0-255), color B (0-255)
    TF_MASK01_LAYER,            ///< Set mask01's layer. Args: layer
    TF_MASK01_FADE,             ///< Fade mask01's opacity. Arg0: TODO; Args: target opacity, time in ticks
    TF_117,
    TF_118,
    TF_119,
    TF_11A,
    TF_11B,
    TF_11C,
    TF_11D,
    TF_11E,
    TF_11F,
    TF_120,
    TF_121,
    TF_122,
    TF_123,
    TF_MESG_PANE_SET_TEXT,      ///< Set a message pane's text. Arg0: access index; Args: mesg ID string
    TF_125,
    TF_126,
    TF_127,
    TF_128,
    TF_129,
    TF_12A,
    TF_12B,
    TF_LOAD_SND_GROUP,          ///< Start loading a sound group. Arg0: type (1 for music, 2 for sfx); Args: SID of group
    TF_UNLOAD_SND_GROUPS,       ///< Unload all groups of a specific type. Arg0: type (1 for music, 2 for sfx)
    TF_RESET_SND_GROUP_HEAP,    ///< Reset a sound group's heap. Arg0: type (1 for music, 2 for sfx)
                                ///      - Note: this doesn't unload any previously loaded data, but it will be
                                ///              overwritten by newly allocated data.
    TF_12F,
    TF_130,
    TF_131,
    TF_132,
    TF_133,
    TF_134,
    TF_135,
    TF_136,
    TF_137,
    TF_138,
    TF_139,
    TF_13A,
    TF_13B,
    TF_13C,
    TF_13D,
    TF_13E,
    TF_REMIX8_MASK_MANAGE,      ///< Manage the Remix 8 mask. Arg0: operation (0: load, 1: unload, 2: enquire ready (sets condvar), 3: init, 4: set visible, 5: set layer); Args: is visible / layer
    TF_ENDLESS_MANAGE,          ///< Manage Endless Remix. Arg0: operation (0: load, 1: unload, 2: enquire ready (sets condvar), 3: init, 4: get random scene ID (sets condvar))
    TF_141
};

// command macros

#define TFC_SET_SCENE(sceneId, tfLabel) TFD_CMD(TF_SET_SCENE, 2, 0), (TickFlowCode)(sceneId), TFD_PTR(tfLabel),
#define TFC_100_1() TFD_CMD(TF_SET_SCENE, 0, 1), // TODO: rename

#define TFC_SET_SCENE_VER(sceneId, ver) TFD_CMD(TF_SET_SCENE_VER, 2, 0), (TickFlowCode)(sceneId), (TickFlowCode)(ver),

#define TFC_SET_EPILOGUE(nameStr, ver) TFD_CMD(TF_SET_EPILOGUE, 2, 0), TFD_PTR(nameStr), (TickFlowCode)(ver),

#define TFC_SET_EPILOGUE_MSG_OK(mesgIdStr) TFD_CMD(TF_SET_EPILOGUE_MSG, 1, 0), TFD_PTR(mesgIdStr),
#define TFC_SET_EPILOGUE_MSG_TRYAGAIN(mesgIdStr) TFD_CMD(TF_SET_EPILOGUE_MSG, 1, 1), TFD_PTR(mesgIdStr),
#define TFC_SET_EPILOGUE_MSG_SUPERB(mesgIdStr) TFD_CMD(TF_SET_EPILOGUE_MSG, 1, 2), TFD_PTR(mesgIdStr),

#define TFC_SET_GRADING_CAPTION(mesgIdStr) TFD_CMD(TF_SET_GRADING_CAPTION, 1, 0), TFD_PTR(mesgIdStr),

#define TFC_FADE_IN_FRAMES(frames) TFD_CMD(TF_FADE, 2, 1), (TickFlowCode)(1), (TickFlowCode)(frames),
#define TFC_FADE_OUT_FRAMES(frames) TFD_CMD(TF_FADE, 2, 0), (TickFlowCode)(1), (TickFlowCode)(frames),

#define TFC_FADE_IN_TICKS(frames) TFD_CMD(TF_FADE, 2, 1), (TickFlowCode)(0), (TickFlowCode)(frames),
#define TFC_FADE_OUT_TICKS(frames) TFD_CMD(TF_FADE, 2, 0), (TickFlowCode)(0), (TickFlowCode)(frames),

#define TFC_UI_SKIP_POS(pos) TFD_CMD(TF_UI_SKIP_POS, 0, pos),

#define TFC_UI_SKIP_ANIM() TFD_CMD(TF_UI_SKIP_ANIM, 1, 0), (TickFlowCode)(0),
#define TFC_UI_SKIP_ANIM_PRACTICE() TFD_CMD(TF_UI_SKIP_ANIM, 1, 0), (TickFlowCode)(1),

#define TFC_MASK01_VISIBLE(isVisible) TFD_CMD(TF_MASK01_VISIBLE, 1, 0), (TickFlowCode)((isVisible) ? 1 : 0),
#define TFC_MASK01_OPACITY(opacity) TFD_CMD(TF_MASK01_OPACITY, 1, 0), (TickFlowCode)(opacity),
#define TFC_MASK01_COLOR(r, g, b) TFD_CMD(TF_MASK01_COLOR, 3, 0), (TickFlowCode)(r), (TickFlowCode)(g), (TickFlowCode)(b),
#define TFC_MASK01_LAYER(layer) TFD_CMD(TF_MASK01_LAYER, 1, 0), (TickFlowCode)(layer),
#define TFC_MASK01_FADE(targetOpacity, ticks) TFD_CMD(TF_MASK01_FADE, 2, 1), (TickFlowCode)(targetOpacity), (TickFlowCode)(ticks),

#define TFC_RESET_SND_GROUP_HEAP(type) TFD_CMD(TF_RESET_SND_GROUP_HEAP, 0, type),

#define TFC_MESG_PANE_SET_TEXT(accessIdx, mesgIdStr) TFD_CMD(TF_MESG_PANE_SET_TEXT, 1, accessIdx), TFD_PTR(mesgIdStr),

// TODO
#define TFC_11A(value) TFD_CMD(TF_11A, 1, 0), (TickFlowCode)(value),

// TODO
#define TFC_11D() TFD_CMD(TF_11D, 0, 0),

#endif
