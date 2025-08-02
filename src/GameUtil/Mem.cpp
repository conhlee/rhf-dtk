#include "Mem.hpp"

MEMiHeapHead *lbl_80320F80; // gHeapMEM1
MEMiHeapHead *lbl_80320F84; // gHeapMEM2
static bool lbl_80320F88; // sHeapInitialized
static u8 lbl_80320F89; 

static u16 lbl_803D5C28[16];

void *fn_801D3784(size_t, EHeapMEM, s32); // doAlloc
void fn_801D3568(void); // initHeap

void *operator new(size_t size) {
    void *object;
    BOOL interrupt;

    if (!lbl_80320F88) {
        fn_801D3568();
    }

    interrupt = OSDisableInterrupts();
    object = MEMAllocFromExpHeap(lbl_80320F84, size);
    OSRestoreInterrupts(interrupt);
    if (object == NULL) {
        OSReport("Can't Alloc Heap\n");
        OSReport(" Required : %d B\n", size);
        OSReport(" Free     : %d B\n", MEMGetTotalFreeSizeForExpHeap(lbl_80320F84));
        OSReport(" Max Size : %d B\n", MEMGetAllocatableSizeForExpHeap(lbl_80320F84));
        OSReport(" Total    : %d B\n", (u8 *)lbl_80320F84->end - (u8 *)lbl_80320F84);
    }
    return object;
}

void *operator new(size_t size, EHeapMEM heap, s32 align) {
    return fn_801D3784(size, heap, align);
}

void *operator new[](size_t size) {
    void *object;
    BOOL interrupt;

    if (!lbl_80320F88) {
        fn_801D3568();
    }

    interrupt = OSDisableInterrupts();
    object = MEMAllocFromExpHeap(lbl_80320F84, size);
    OSRestoreInterrupts(interrupt);
    if (object == NULL) {
        OSReport("Can't Alloc Heap\n");
        OSReport(" Required : %d B\n", size);
        OSReport(" Free     : %d B\n", MEMGetTotalFreeSizeForExpHeap(lbl_80320F84));
        OSReport(" Max Size : %d B\n", MEMGetAllocatableSizeForExpHeap(lbl_80320F84));
        OSReport(" Total    : %d B\n", (u8 *)lbl_80320F84->end - (u8 *)lbl_80320F84);
    }
    return object;
}

void *operator new[](size_t size, EHeapMEM heap, s32 align) {
    return fn_801D3784(size, heap, align);
}

void operator delete(void *mem) {
    BOOL interrupt;

    interrupt = OSDisableInterrupts();
    if (mem != NULL) {
        MEMiHeapHead *found = MEMFindContainHeap(mem);
        if (found == lbl_80320F80) {
            MEMFreeToExpHeap(lbl_80320F80, mem);
        } else if (found == lbl_80320F84) {
            MEMFreeToExpHeap(lbl_80320F84, mem);
        }
    }
    OSRestoreInterrupts(interrupt);
}

void operator delete[](void *mem) {
    BOOL interrupt;

    interrupt = OSDisableInterrupts();
    if (mem != NULL) {
        MEMiHeapHead *found = MEMFindContainHeap(mem);
        if (found == lbl_80320F80) {
            MEMFreeToExpHeap(lbl_80320F80, mem);
        } else if (found == lbl_80320F84) {
            MEMFreeToExpHeap(lbl_80320F84, mem);
        }
    }
    OSRestoreInterrupts(interrupt);
}

void fn_801D3564(void) {

}

// Initialize the heaps
void fn_801D3568(void) {
    if (!lbl_80320F88) {
        void *arena1Lo = OSGetMEM1ArenaLo();
        void *arena1Hi = OSGetMEM1ArenaHi();
        lbl_80320F80 = MEMCreateExpHeapEx(arena1Lo, (u8 *)arena1Hi - (u8 *)arena1Lo, 0);
        OSSetMEM1ArenaLo(arena1Hi);

        void *arena2Lo = OSGetMEM2ArenaLo();
        void *arena2Hi = OSGetMEM2ArenaHi();
        u32 size = (u8 *)arena2Hi - (u8 *)arena2Lo;
        if (size > 0x4000000) {
            size -= 0x4000000;
            arena2Hi = (void *)((u8 *)arena2Hi - 0x4000000);
        }
        lbl_80320F84 = MEMCreateExpHeapEx(arena2Lo, size, 0);
        OSSetMEM2ArenaLo(arena2Hi);
        lbl_80320F88 = 1;
        lbl_80320F89 = 0;
        MEMSetGroupIDForExpHeap(lbl_80320F80, 0);
        MEMSetGroupIDForExpHeap(lbl_80320F84, 0);
    }
}

void fn_801D3634(void) {

}

void fn_801D3638(u32 arg0) {

}

u16 fn_801D363C(void) {
    return MEMGetGroupIDForExpHeap(lbl_80320F80);
}

void fn_801D3644(void) {
    u32 id;

    id = lbl_803D5C28[--lbl_80320F89];
    MEMSetGroupIDForExpHeap(lbl_80320F80, id);
    MEMSetGroupIDForExpHeap(lbl_80320F84, id);
}

void fn_801D369C(u16 id) {
    lbl_803D5C28[lbl_80320F89++] = MEMGetGroupIDForExpHeap(lbl_80320F80);
    MEMSetGroupIDForExpHeap(lbl_80320F80, id);
    MEMSetGroupIDForExpHeap(lbl_80320F84, id);
}

void fn_801D3700(void *mem, MEMiHeapHead *heap, u32 id) {
    if (id == MEMGetGroupIDForMBlockExpHeap(mem)) {
        MEMFreeToExpHeap(heap, mem);
    }
}

void fn_801D375C(u32 id) {
    MEMVisitAllocatedForExpHeap(lbl_80320F80, fn_801D3700, id);
}

void fn_801D3770(u32 id) {
    MEMVisitAllocatedForExpHeap(lbl_80320F84, fn_801D3700, id);
}

void *fn_801D3784(size_t size, EHeapMEM heap, s32 align) {
    void *object;
    BOOL interrupt;

    if (!lbl_80320F88) {
        fn_801D3568();
    }

    interrupt = OSDisableInterrupts();
    object = NULL;

    if (heap == eHeap_MEM1) {
        if (align == 0) {
            object = MEMAllocFromExpHeap(lbl_80320F80, size);
        } else {
            object = MEMAllocFromExpHeapEx(lbl_80320F80, size, align);
        }
    } else if (heap == eHeap_MEM2) {
        if (align == 0) {
            object = MEMAllocFromExpHeap(lbl_80320F84, size);
        } else {
            object = MEMAllocFromExpHeapEx(lbl_80320F84, size, align);
        }
    }
    OSRestoreInterrupts(interrupt);
    if (object == NULL) {
        OSReport("Can\'t Alloc Heap\n");
        OSReport(" Required : %d B\n", size);
        OSReport(" Free     : %d B\n", 
            (heap == eHeap_MEM1) ? MEMGetTotalFreeSizeForExpHeap(lbl_80320F80) : MEMGetTotalFreeSizeForExpHeap(lbl_80320F84));
        OSReport(" Max Size : %d B\n", 
            (heap == eHeap_MEM1) ? MEMGetAllocatableSizeForExpHeap(lbl_80320F80) : MEMGetAllocatableSizeForExpHeap(lbl_80320F84));
        OSReport(" Total    : %d B\n",
            (heap == eHeap_MEM1) ? (u32)(lbl_80320F80->end - (u32)lbl_80320F80) : (u32)(lbl_80320F84->end - (u32)lbl_80320F84));
    }
    return object;
}