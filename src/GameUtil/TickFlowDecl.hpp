#ifndef GAMEUTIL_TICKFLOWDECL_HPP
#define GAMEUTIL_TICKFLOWDECL_HPP

#include <revolution/types.h>

typedef u32 TickFlowCode;

enum {
    /*   TickFlow opcodes (0x000 to 0x050)   */

    TF_ASYNC_CALL = 0x000, ///< Args: TickFlowCode *, delay in ticks
    TF_CALL, ///< Args: TickFlowCode *
    TF_RETURN, // Return to the previous call.
    TF_STOP, // End execution.
    TF_CATEGORY, ///< Set category. Args: category to set
    TF_SET_CONDVAR, ///< Args: value to set condvar to
    TF_INCR_CONDVAR, ///< Args: value to increment condvar by
    TF_PUSH_CONDVAR,
    TF_POP_CONDVAR,
    TF_REST, ///< Arg0: ticks to rest for
    TF_00A,
    TF_REST_FRAMES, ///< Arg0: frames to rest for
    TF_UNREST, ///< Arg0: ticks to decrement the current rest by
    TF_00D,
    TF_LABEL, ///< Arg0: label identifier
    TF_JUMP, ///< Arg0: identifier of label to jump to
    TF_IF, ///< TODO Multiple variations depending on arg0. Args: value to compare to condvar
    TF_ELSE,
    TF_ENDIF,
    TF_SWITCH_BEGIN,
    TF_SWITCH_CASE, ///< Arg0: value to compare to condvar
    TF_SWITCH_BREAK,
    TF_SWITCH_DEFAULT,
    TF_SWITCH_END,
    TF_018,
    TF_019,
    TF_TEMPO, ///< Set tempo. Arg0: BPM to set
    TF_TEMPO_SEQ, ///< Set tempo. Arg0: SID of sequence to reference BPM from
    TF_TEMPO_WAVE, ///< Set tempo. Arg0: SID of wave to reference BPM from
    TF_SPEED, ///< Set speed. Arg0: Speed value (fixed, 256)
    TF_01E,
    TF_01F,
    TF_020,
    TF_SPAWN_CELLANIM, ///< Create and display a new CellAnim. Arg0: TODO; Args: cell ID, anim ID, pos X, pos Y, display layer, scale X, scale Y
    TF_PLAY_SFX_VOL, ///< Play a SFX. Args: SID of SFX, volume (fixed, 256)
    TF_PLAY_SFX, ///< Play a SFX. Arg0: TODO; Args: SID of SFX, volume, pitch, pan, (UNUSED), start offset (all args are fixed, 256)
    TF_024,
    TF_025,
    TF_026,
    TF_027,
    TF_028,
    TF_029,
    TF_02A,
    TF_02B,
    TF_02C,
    TF_02D,
    TF_02E,
    TF_02F,
    TF_030,
    TF_031,
    TF_032,
    TF_033,
    TF_034,
    TF_035,
    TF_036,
    TF_PREPARE_WAVE, ///< Prepare WSD (wave sound data) for playback. Arg0: SID of WSD
    TF_038,
    TF_PLAY_WAVE, ///< Start WSD (wave sound data) playback.
    TF_03A,
    TF_03B,
    TF_GET_WAVE_READY, ///< Set condvar to 1 if WSD (wave sound data) is ready, and 0 if not.
    TF_03D,
    TF_03E,
    TF_GET_GROUP_LOADING, ///< Set condvar to 1 if the current group is loading, and 0 if not.
    TF_MESG_PANE_VISIBLE, ///< Set a message pane's visibillity. Arg0: access index; Args: is visible
    TF_041,
    TF_042,
    TF_043,
    TF_044,
    TF_045,
    TF_046,
    TF_047,
    TF_048,
    TF_SET_SKIPPABLE, ///< Set if the player is allowed to skip. Arg0: enabled
    TF_SET_SKIP_HANDLER, ///< Set the TickFlow that runs when a skip is triggered. Args: TickFlowCode *
    TF_04B,
    TF_04C,
    TF_04D,
    TF_04E,
    TF_RANDOM, ///< Set the condvar to a random value. Arg0: upper bound of random value

    /*   ExFlow opcodes (0x100 to 0x141) are found in Game/ExFlowDecl.hpp */
};

// decl macros

#define TFD_BEGIN(name) const TickFlowCode name[] = {
#define TFD_END() \
    }             \
    ;

#define TFD_EXTERN(name) extern const TickFlowCode name[];

#define TFD_STOP() \
    TF_STOP        \
    TFD_END()
#define TFD_RETURN() \
    TF_RETURN        \
    TFD_END()

#define TFD_CMD(command, argc, arg0) (               \
    (((TickFlowCode)(command) & 0x3FFu)  <<  0) | /* 10bit */ \
    (((TickFlowCode)(argc)    & 0xFu)    << 10) | /* 4bit  */ \
    (((TickFlowCode)(arg0)    & 0x3FFFu) << 14)   /* 14bit */ \
)

#define TFD_PTR(ptr) ((TickFlowCode)(const void *)(ptr))

// command macros

#define TFC_ASYNC_CALL(tfLabel, delay) TFD_CMD(TF_ASYNC_CALL, 2, 0), TFD_PTR(tfLabel), (TickFlowCode)(delay),
#define TFC_CALL(tfLabel) TFD_CMD(TF_CALL, 1, 0), TFD_PTR(tfLabel),

#define TFC_CATEGORY(category) TFD_CMD(TF_CATEGORY, 1, 0), (TickFlowCode)(category),

#define TFC_REST(ticks) TFD_CMD(TF_REST, 0, ticks),
#define TFC_REST_FRAMES(frames) TFD_CMD(TF_REST_FRAMES, 0, frames),

#define TFC_IF_EQU(value) TFD_CMD(TF_IF, 1, 0), (TickFlowCode)(value),
#define TFC_IF_NEQ(value) TFD_CMD(TF_IF, 1, 1), (TickFlowCode)(value),
#define TFC_IF_LT(value) TFD_CMD(TF_IF, 1, 2), (TickFlowCode)(value),
#define TFC_IF_LEQ(value) TFD_CMD(TF_IF, 1, 3), (TickFlowCode)(value),
#define TFC_IF_GT(value) TFD_CMD(TF_IF, 1, 4), (TickFlowCode)(value),
#define TFC_IF_GEQ(value) TFD_CMD(TF_IF, 1, 5), (TickFlowCode)(value),

#define TFC_ELSE() TFD_CMD(TF_ELSE, 0, 0),

#define TFC_ENDIF(value) TFD_CMD(TF_ENDIF, 0, 0),

#define TFC_TEMPO(tempo) TFD_CMD(TF_TEMPO, 0, tempo),

#define TFC_TEMPO_WAVE(sid) TFD_CMD(TF_TEMPO_WAVE, 0, sid),

#define TFC_SPEED(speed) TFD_CMD(TF_SPEED, 0, speed),

#define TFC_PLAY_SFX(sid) TFD_CMD(TF_PLAY_SFX, 1, 0), (TickFlowCode)(sid),

#define TFC_PREPARE_WAVE(sid) TFD_CMD(TF_PREPARE_WAVE, 0, sid),
#define TFC_PLAY_WAVE() TFD_CMD(TF_PLAY_WAVE, 0, 0),

#define TFC_MESG_PANE_VISIBLE(accessIdx, isVisible) TFD_CMD(TF_MESG_PANE_VISIBLE, 1, accessIdx), (TickFlowCode)((isVisible) ? 1 : 0),

#define TFC_SET_SKIPPABLE(isSkippable) TFD_CMD(TF_SET_SKIPPABLE, 0, (isSkippable) ? 1 : 0),

#define TFC_SET_SKIP_HANDLER(tfLabel) TFD_CMD(TF_SET_SKIP_HANDLER, 1, 0), TFD_PTR(tfLabel),

#endif
