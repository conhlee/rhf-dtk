#ifndef GAMEUTIL_MEM_HPP
#define GAMEUTIL_MEM_HPP

#include <revolution/types.h>
#include <revolution/OS.h>
#include <revolution/MEM.h>

enum EHeapMEM {
    eHeap_MEM1 = 0,
    eHeap_MEM2 = 1,
};

extern MEMiHeapHead *lbl_80320F80; // gHeapMEM1
extern MEMiHeapHead *lbl_80320F84; // gHeapMEM2

void *operator new(size_t);
void *operator new(size_t, EHeapMEM, s32);
void *operator new[](size_t);
void *operator new[](size_t, EHeapMEM, s32);
void operator delete(void *);
void operator delete[](void *);

inline void *operator new(size_t, void *p) { return p; }

void fn_801D3564(void);
void fn_801D3634(void);
void fn_801D3638(u32);
u16 fn_801D363C(void);

void fn_801D3644(void);
void fn_801D369C(u16);
void fn_801D3700(void *, MEMiHeapHead *, u32);
void fn_801D375C(u32);
void fn_801D3770(u32);

#endif