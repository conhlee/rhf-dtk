#include "InputCheckManager.hpp"
#include "Mem.hpp"
#include "Controller.hpp"
#include "TickFlowManager.hpp"
#include "CheckPointManager.hpp"

const u32 lbl_802E4FE0[] = {
    0x8, 0x4, 0x1, 0x2,
    0x8000, 0x10, 0x1000, 0x200,
    0x100, 0x2000, 0x4000,
};
const u32 lbl_802E500C[] = {
    0, 1, 2, 3, 7, 8, 9, 0xa,
    0xb, 0xc, 0xd,
};
const u32 lbl_802E5038[] = {
    0xe, 0xf, 0x10, 0x11, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x1a,
    0x1b,
};

static u8 lbl_803D5D78[16];

void CInputCheckManager::fn_801E8118(void) {
    for (int i = 0; i < 4; i++) {
        CController *controller = gControllerManager->fn_801D5FF0(i);
        for (int j = 0; j < 11; j++) {
            if (controller->getUnk133C() & lbl_802E4FE0[j]) {
                gInputCheckManager->fn_801E923C(lbl_802E500C[j] + i * 0x1c);
            } else if (controller->getUnk1340() & lbl_802E4FE0[j]) {
                gInputCheckManager->fn_801E923C(lbl_802E5038[j] + i * 0x1c);
            }
        }
        if (controller->unk136CCheck() && gInputCheckManager->getUnk42E()) {
            gInputCheckManager->fn_801E923C(i * 0x1c + 6);
            lbl_803D5D78[i + 0] = 0;
            lbl_803D5D78[i + 8] = 0;
        } else {
            // TODO: here
        }
    }
}

void CInputCheckManager::fn_801E8560(void) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(lbl_803D5D78); i++) {
        lbl_803D5D78[i] = 0;
    }
}

s32 CInputCheckManager::fn_801E85AC(u32 arg0) {
    if (0x1b >= arg0) {
        return 0;
    }
    if ((0x1c <= arg0) && (0x37 >= arg0)) {
        return 1;
    }
    if ((0x38 <= arg0) && (0x53 >= arg0)) {
        return 2;
    }
    if ((0x54 <= arg0) && (0x6f >= arg0)) {
        return 3;
    }
    return -1;
}

CInputCheckManager::CInputCheckManager(void) {

}

CInputCheckManager::~CInputCheckManager(void) {
    _08();
}

void CInputCheckManager::_10(u32 size) {
    size = ROUND_UP(size, 32);
    unk04 = new (eHeap_MEM2, 32) u8[size];
    unk08 = MEMCreateExpHeap(unk04, size);
}

void CInputCheckManager::_08(void) {
    unk0C->removeAll();
    unk0C = 0;
    MEMDestroyExpHeap(unk08);
    delete[] unk04;
}

void CInputCheckManager::_14(void) {
    unk0C = 0;
    unk418 = 0;
    unk414 = fn_801E8118;
    unk410 = 0;
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk10); i++) {
        unk10[i].unk0 = 0;
    }
    unk41C = 0;
    unk429 = 1;
    unk42E = 0;
    unk484 = 0;
    unk42A = 1;
    unk42B = 1;
    unk42C = 1;
    unk42D = 1;
    unk42F = 1;
    fn_801E960C();
    unk49C = 0;
    unk4A0 = .0f;
    resetUnk4A4();
    unk8A4 = fn_801E85AC;
    unk48C = 0;
    unk48D = 0;
}

void CInputCheckManager::fn_801E8A08(void) {
    if (unk41C) {
        return;
    }

    if (!unk48D && !unk484) {
        unk414();
    }
    fn_801E8BD0();

    resetUnk10();

    resetUnk0C();
}


// regswaps, missing code (may be nonequivalent)
void CInputCheckManager::fn_801E8BD0(void) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk10); i++) {
        if (!unk10[i].unk0) {
            continue;
        }
        u32 temp_r23 = 0;
        u32 temp_r20 = unk4A4[unk10[i].unk4];
        for (CInputChecker *cur = unk0C, *next; cur != NULL; cur = next) {
            next = cur->getNext();
            if (!cur->getUnk71()) {
                if (!cur->fn_801E7E28(temp_r20)) {
                    continue;
                }
                u8 temp_r4;
                s32 temp_r27 = unkCheck(temp_r20) && (unk474[unk8A4(temp_r20)] > (f64)0);
                u8 sp8 = 0;
                switch ((temp_r27 = cur->_20(&sp8, temp_r27, unk10[i].unk8))) {
                    case 0:
                        temp_r23 = 1;
                        if (!cur->_24(temp_r20)) {
                            break;
                        }
                        unkInline(sp8);
                        gCheckPointManager->fn_801EAF2C(cur->getUnk78(), 0);
                        break;
                    case 1:
                        temp_r23 = 1;
                        if (!cur->_28(temp_r20)) {
                            break;
                        }
                        unkInline(sp8);
                        gCheckPointManager->fn_801EAF2C(cur->getUnk78(), 1);
                        break;
                    default:
                        break;
                }
                if ((temp_r27 == 2) || !cur->getUnk70() || cur->getUnk50()) {
                    continue;
                }
                if (cur == unk0C) {
                    unk0C = cur->getNext();
                }
                cur->removeCurrent();
            } else {
                if (cur->getUnk72() || !cur->getUnk50() || (cur->getUnk74() > 1)) {
                    continue;
                }
                if (!cur->fn_801E7E70(temp_r20)) {
                    continue;
                }
                temp_r23 = 1;
                if (cur->_30(temp_r20)) {
                    switch ((s32)cur->getUnk74()) {
                        case 0:
                            gCheckPointManager->fn_801EB00C(cur->getUnk78(), 0);
                            break;
                        case 1:
                            gCheckPointManager->fn_801EB00C(cur->getUnk78(), 1);
                            break;
                        default:
                            break;
                    }
                }
                if (!cur->getUnk70()) {
                    continue;
                }
                if (cur == unk0C) {
                    unk0C = cur->getNext();
                }
                cur->removeCurrent();
            }
        }
        // 3ec
        if (temp_r23) {
            unk10[i].unk0 = 0;
            continue;
        }
        if (0 != unk10[i].unkC) {
            continue;
        }
        unk10[i].unk0 = 0;
        if (unk418) {
            unk418(temp_r20);
        }
        fn_801E94E8(temp_r20);
        if (!gCheckPointManager->getUnkDD()) {
            continue;
        }
        if (unk428 >= 6) {
            continue;
        }
        unk428++;
    }
}

// ...

void CInputCheckManager::fn_801E94E8(u32 arg0) {
    if (!unk42F) {
        return;
    }
    if (!checkUnk430(arg0)) {
        return;
    }
    s32 idx = unk8A4(arg0);
    unk474[idx] = unk470;
}