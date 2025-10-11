#ifndef GAME_SNDHEAP_HPP
#define GAME_SNDHEAP_HPP

#include <revolution/types.h>

enum ESoundHeap {
    eSoundHeap_0, // Common & Practice
    eSoundHeap_1, // Game BGM
    eSoundHeap_2, // Game SFX
    eSoundHeap_3, // Prologue BGM

    eSoundHeap_Count
};

void fn_8008357C(void);

void fn_80083630(u16 groupID, ESoundHeap heap);
void fn_8008364C(u16 groupID, ESoundHeap heap);

void fn_80083668(ESoundHeap heap);

void fn_8008367C(ESoundHeap heap);
void fn_800836C0(ESoundHeap heap);

void fn_800836E0(bool);

#endif