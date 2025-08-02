#include <string.h>
#include <revolution/PAD.h>
#include <revolution/KPAD.h>
#include <revolution/WPAD.h>
#include <nw4r/math/triangular.h>
#include "Controller.hpp"
#include "Mem.hpp"
#include "TickFlowManager.hpp"

/*

        CController

*/

CController::CController(s32 i) {
    unk04 = i;
    unk136D = false;
    unk136C = false;
    unk1370 = 0;
    unk1375 = 0;
    unk1338 = 0;
    unk133C = 0;
    unk1340 = 0;
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1344); i++) {
        unk1344[i] = 0;
    }
    unk1364 = 10;
    unk1365 = 4;
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1354); i++) {
        if ((u16)(1 << i)) {
            unk1354[i] = 0;
        }
    }

    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1354); i++) {
        if (((1 << i) & (0x800 | 0x400))) {
            unk1354[i] = 6;
        }
    }
}

void CController::_0C(void) {
    unk1398 = false;
}

void CController::_10(void) {
    u32 temp_r30 = unk1338;
    fn_801D4DDC();
    fn_801D4E38(temp_r30);
    unk1368 = 0;
    fn_801D4F74(temp_r30);
    fn_801D4FD8();

    KPADSetPosParam(unk04, .05f, .8f);
    if (unk18[0].speed < .01f) {
        KPADSetPosParam(unk04, .05f, .13f);
    }
}

void CController::_14(void) {
    _4C();
}

void CController::fn_801D4DDC(void) {
    unk10 = WPADProbe(unk04, &unk0C);
    unk08 = KPADRead(unk04, unk18, ARRAY_LENGTH(unk18));
    KPADGetUnifiedWpadStatus(unk04, unkF18, unk08);
}

void CController::fn_801D4E38(u32 arg1) {
    do801D4EA4(arg1);
}

void CController::fn_801D4EA4(u32 arg1, u32 arg2) {
    u32 xorinput = arg2 ^ arg1;
    unk1338 = 0;
    unk133C = 0;
    unk1340 = 0;
    u32 xorarg1 = xorinput & arg1;
    u32 xorarg2 = xorinput & arg2;

    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1344); i++) {
        u32 temp_r12 = 1 << i;
        if (unk1344[i]) {
            if (gTickFlowManager->getUnk6D()) {
                continue;
            }
            unk1344[i]--;
            if ((unk1344[i] == 0) && (arg1 & temp_r12)) {
                unk1344[i] = 1;
            }
        } else {
            if (arg1 & temp_r12) {
                unk1338 |= temp_r12;
            }
            if (xorarg1 & temp_r12) {
                unk133C |= temp_r12;
            }
            if (xorarg2 & temp_r12) {
                unk1340 |= temp_r12;
                if (!gTickFlowManager->getUnk6D()) {
                    unk1344[i] = unk1354[i];
                }
            }
        }
    }
}

void CController::fn_801D4F74(u32 arg1) {
    unk1368 = 0;
    if (unk133C) {
        unk1366 = 0;
    }
    if (arg1 == unk1338) {
        unk1366++;
        if ((unk1366 == unk1364) || (unk1366 == (unk1364 + unk1365))) {
            unk1368 = unk1338;
            unk1366 = unk1364;
        }
    }
}

void CController::fn_801D4FD8(void) {
    u32 temp;
    unk136D = unk136C;
    if (!unk136D) {
        if ((unk1370 - 1) > 1) { // TODO: maybe fake?
            if (!unk1370) {
                temp = unk133C;
                if (((temp >> 11) & 1) && (temp & 0x400)) {
                    unk1370 = 3;
                    unk136C = true;
                    return;
                }
                if ((temp >> 11) & 1) {
                    unk1370 = 1;
                    unk1374 = 0;
                    return;
                }
                if (temp & 0x400) {
                    unk1370 = 2;
                    unk1374 = 0;
                }
            }
            return;
        }
        unk1374++;
        if (unk1374 >= 4) {
            unk1370 = 0;
            return;
        }
        if (((unk133C & 0x800)) || ((unk133C & 0x400))) {
            unk1370 = 3;
            unk136C = true;
        }
        return;
    }
    if ((unk1370 - 1) > 1) { // TODO: maybe fake?
        if ((s32)unk1370 != 3) {
            return;
        }
        temp = unk1340;
        if (((temp >> 11) & 1) && (temp & 0x400)) {
            unk1370 = 0;
            unk136C = false;
            return;
        }
        if ((temp >> 11) & 1) {
            unk1370 = 2;
            unk1374 = 0;
            return;
        }
        if (temp & 0x400) {
            unk1370 = 1;
            unk1374 = 0;
        }
        return;
    }
    unk1374++;
    if (unk1374 >= 4) {
        unk1370 = 0;
        unk136D = false;
        unk136C = false;
        return;
    }
    if (((unk1340 & 0x800)) || ((unk1340 & 0x400))) {
        unk1370 = 0;
        unk136C = false;
    }
    return;
}

void CController::fn_801D5170(bool arg1) {
    if (arg1) {
        KPADSetPosParam(unk04, .05f, .8f);
        if (unk18[0].speed < .01f) {
            KPADSetPosParam(unk04, .05f, .13f);
        }
    } else {
        KPADSetPosParam(unk04, .0f, 1.0f);
    }
}

// TODO: stack madness
Vec2 CController::fn_801D51E4(f32 arg1, f32 arg2) {
    Vec2 pos = unk18[0].pos;
    Vec2 p = unk18[0].pos;

    p.x = (arg1 * pos.x) / 2.0f;
    p.y = (arg2 * pos.y) / 2.0f;
    return p;
}

// TODO: lots of things wrong
Vec2 CController::fn_801D523C(CLayout *arg1) {
    nw4r::ut::Rect rect = arg1->getLayout()->GetLayoutRect();
    return fn_801D51E4(rect.left - rect.right, rect.bottom - rect.top);
}

bool CController::fn_801D52D4(void) {
    bool out = false;
    if (_24() && (unk08 > 0) && (unk18[0].dpd_valid_fg)) {
        out = true;
    }
    return out;
}

bool CController::fn_801D5340(void) {
    // TODO: maybe inlines here?
    bool temp_r30 = false;
    bool temp_r29 = false;
    bool temp_r28 = false;
    bool temp_r27 = false;
    if (fn_801D52D4()) {
        Vec2 a = unk18[0].pos;
        if (-1.0f <= a.x) {
            temp_r27 = true;
        }
    }
    if (temp_r27) {
        Vec2 a = unk18[0].pos;
        if (a.x <= 1.0f) {
            temp_r28 = true;
        }
    }
    if (temp_r28) {
        Vec2 a = unk18[0].pos;
        if (-1.0f <= a.y) {
            temp_r29 = true;
        }
    }
    if (temp_r29) {
        Vec2 a = unk18[0].pos;
        if (a.y <= 1.0f) {
            temp_r30 = true;
        }
    }
    return temp_r30;
}


f32 CController::fn_801D547C(void) {
    static Vec2 lbl_80320F90;

    if (_24() && (unk08 > 0)) {
        lbl_80320F90 = unk18[0].horizon;
    }
    Vec2 temp = lbl_80320F90;
    return 1.40625f * nw4r::math::Atan2FIdx(temp.y, temp.x);
}

void CController::fn_801D5500(u32 arg1, u8 arg2) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1354); i++) {
        if (arg1 & (1 << i)) {
            unk1354[i] = arg2;
        }
    }
}

void CController::fn_801D55D8(u32 arg1, u8 arg2) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk1354); i++) {
        if (arg1 & (1 << i)) {
            unk1344[i] = arg2;
        }
    }
}

void CController::_40(const char *arg1, bool arg2) {
    if (!unk1375 || arg2) {
        u32 len = strlen(arg1);
        unk1375 = 1;
        unk1376 = 0;
        for (int j = 0; j < len; j++) {
            if (arg1[j] == '*') {
                unk1377[j] = 1;
            } else if (arg1[j] == '-') {
                unk1377[j] = 0;
            }
        }
        unk1377[len] = -1;
        _4C();
    }
}

void CController::_44(void) {
    unk1375 = 0;
    WPADControlMotor(unk04, 0);
}

void CController::_4C(void) {
    if (unk1375) {
        if ((unk1377[unk1376]) == 1) {
            WPADControlMotor(unk04, 1);
            unk1376++;
        } else if (unk1377[unk1376] == 0) {
            WPADControlMotor(unk04, 0);
            unk1376++;
        } else if (unk1377[unk1376] == (u8)-1) {
            WPADControlMotor(unk04, 0);
            unk1375 = 0;
        }
    }
}

void CController::fn_801D5830(s32 arg0, s32 arg1) {
    CController *controller = gControllerManager->getController(arg0);
    controller->unk139C = arg1;
    controller->unk1398 = false;
}

bool CController::fn_801D5850(void) {
    unk1398 = true;
    unk139C = WPADGetInfoAsync(unk04, &unk13A0, CController::fn_801D5830);
    return !unk139C;
}

bool CController::fn_801D58A0(void) {
    return unk1398;
}

u32 CController::fn_801D58A8(void) {
    return (!unk139C) ? unk13A0.battery : unk139C; 
}

void CGCController::_0C(void) {
    if (unk08->err) {
        return;
    }
    u16 unk0Cbutton = unk0C->button;
    unk14 = 0;
    if (unk08->button & (unk0C->button ^ unk08->button)) {
        unk12 = 0;
    }

    if (unk0Cbutton != unk08->button) {
        return;
    }

    unk12++;
    if ((unk12 == unk10) || (unk12 == (unk10 + unk11))) {
        unk14 = unk08->button;
        unk12 = unk10;
    }
}







/* 

        CControllerManager

*/

void *CControllerManager::fn_801D5950(u32 arg0) {
    return gControllerManager->doAlloc(arg0);
}

u8 CControllerManager::fn_801D59B0(void *arg0) {
    return gControllerManager->doFree(arg0);
}

CControllerManager::CControllerManager(void) {

}

CControllerManager::~CControllerManager(void) {
    _08();
}

void CControllerManager::_10(CController *fn(s32 arg0)) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk04); i++) {
        unk04[i] = fn(i);
    }

    unk14 = new CNullController(-1);
    u32 wpadWorkMemSize = WPADGetWorkMemorySize() + 0x100;
    unk2C = new (eHeap_MEM2, 32) u8[wpadWorkMemSize];
    unk18 = MEMCreateExpHeap(unk2C, wpadWorkMemSize);
    MEMInitAllocatorForExpHeap(&unk1C, unk18, 32);
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk30); i++) {
        unk30[i] = new CGCController(i);
        unk30[i]->setUnk08(&unk40[i]);
        unk30[i]->setUnk0C(&unk70[i]);
    }
}

void CControllerManager::_08(void) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk04); i++) {
        delete unk04[i];
    }
    delete unk14;
    MEMDestroyExpHeap(unk18);
    delete[] unk2C;
}

void CControllerManager::_14(void) {
    WPADRegisterAllocator(CControllerManager::fn_801D5950, CControllerManager::fn_801D59B0);
    KPADInit();
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk04); i++) {
        unk04[i]->_0C();
    }
    PADInit();
    memset(unk40, 0, sizeof(unk40));
    memset(unk70, 0, sizeof(unk70));
    u8 pos = WPADGetSensorBarPosition();
    if (pos == 0) {
        KPADSetSensorHeight(0, -.1f);
        return;
    }
    if (pos == 1) {
        KPADSetSensorHeight(0, .1f);
        return;
    }
}

void CControllerManager::_18(void) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk04); i++) {
        unk04[i]->_10();
    }
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk30); i++) {
        unk30[i]->_0C();
        unk70[i] = unk40[i];
    }
    PADRead(unk40);
    u32 reset = 0;
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk40); i++) {
        if (unk40[i].err == PAD_ERR_NO_CONTROLLER) {
            reset |= (PAD_CHAN0_BIT >> i);
        }
    }
    if (reset) {
        PADReset(reset);
    }
}

void CControllerManager::_1C(void) {
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk04); i++) {
        unk04[i]->_14();
    }
    for (int i = 0; i < (s32)ARRAY_LENGTH(unk30); i++) {
        unk30[i]->_10();
    }
}

CController *CControllerManager::fn_801D5FF0(s32 idx) {
    return unk04[idx];
}

CGCController *CControllerManager::fn_801D6000(s32 idx) {
    return unk30[idx];
}

CGCController::~CGCController(void) {

}

bool CNullController::_3C(void) {
    return false;
}

bool CNullController::_38(void) {
    return false;
}

bool CNullController::_34(void) {
    return false;
}

bool CNullController::_30(void) {
    return false;
}

bool CNullController::_2C(void) {
    return false;
}

bool CNullController::_28(void) {
    return false;
}

bool CNullController::_24(void) {
    return false;
}

u8 CNullController::_18(void) {
    return -3;
}
