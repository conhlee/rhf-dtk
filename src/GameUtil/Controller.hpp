#ifndef GAMEUTIL_CONTROLLERMANAGER_HPP
#define GAMEUTIL_CONTROLLERMANAGER_HPP

#include <revolution/types.h>
#include <revolution/OS.h>
#include <revolution/MEM.h>
#include <revolution/PAD.h>
#include <revolution/KPAD.h>
#include "Singleton.hpp"
#include "Layout.hpp"


class CController {
public:

    virtual ~CController(void) {

    }
    virtual void _0C(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual u8 _18(void) {
        return 0; // TODO
    }
    virtual bool _1C(void) {
        return false; // TODO
    }
    virtual bool _20(void) {
        return false; // TODO
    }
    virtual bool _24(void) {
        return false; // TODO
    }
    virtual bool _28(void) {
        return false; // TODO
    }
    virtual bool _2C(void) {
        return false; // TODO
    }
    virtual bool _30(void) {
        return false; // TODO
    }
    virtual bool _34(void) {
        return false; // TODO
    }
    virtual bool _38(void) {
        return false; // TODO
    }
    virtual bool _3C(void) {
        return false; // TODO
    }
    virtual void _40(const char *, bool);
    virtual void _44(void);
    virtual bool _48(void) {
        return false; // TODO
    }
    virtual void _4C(void);

    CController(s32);
    void fn_801D4DDC(void);
    void fn_801D4E38(u32);
    void fn_801D4EA4(u32, u32);
    void fn_801D4F74(u32);
    void fn_801D4FD8(void);
    void fn_801D5170(bool);
    Vec2 fn_801D51E4(f32, f32);
    Vec2 fn_801D523C(CLayout *);
    bool fn_801D52D4(void);
    bool fn_801D5340(void);
    f32 fn_801D547C(void);
    void fn_801D5500(u32, u8);
    void fn_801D55D8(u32, u8);
    bool fn_801D5850(void);
    bool fn_801D58A0(void);
    u32 fn_801D58A8(void);

    void do801D4EA4(u32 arg0) {
        u32 temp = unk18[0].hold;
        if (!_24()) {
            temp = 0;
        }
        fn_801D4EA4(temp, arg0);
    }

    u32 getUnk133C(void) {
        return unk133C;
    }
    u32 getUnk1340(void) {
        return unk1340;
    }
    u32 getUnk1368(void) {
        return unk1368;
    }
    bool unk136CCheck(void) {
        return unk136C && !unk136D;
    }
private:

    static void fn_801D5830(s32, s32); // WPADCallback

    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    u32 unk14;
    KPADStatus unk18[16];
    u8 pad858[0xf18 - 0x858];
    KPADUnifiedWpadStatus unkF18[16];
    u8 pad1298[0x1338 - 0x1298];
    u32 unk1338;
    u32 unk133C;
    u32 unk1340;
    u8 unk1344[0x10];
    u8 unk1354[0x10];
    u8 unk1364;
    u8 unk1365;
    u8 unk1366;
    u32 unk1368;
    bool unk136C;
    bool unk136D;
    u32 unk1370;
    u8 unk1374;
    u8 unk1375;
    u8 unk1376;
    u8 unk1377[0x21];
    bool unk1398;
    s32 unk139C;
    WPADInfo unk13A0;
};

class CNullController : public CController {
public:

    virtual ~CNullController(void) {

    }

    virtual u8 _18(void);
    virtual bool _24(void);
    virtual bool _28(void);
    virtual bool _2C(void);
    virtual bool _30(void);
    virtual bool _34(void);
    virtual bool _38(void);
    virtual bool _3C(void);

    CNullController(s32 arg0) : CController(arg0) {

    }
private:
};

class CGCController {
public:

    virtual ~CGCController(void);
    virtual void _0C(void);
    virtual void _10(void) {

    }

    CGCController(s32 i) {
        unk04 = i;
        unk10 = 10;
        unk11 = 4;
    }

    void setUnk08(PADStatus *arg0) {
        unk08 = arg0;
    }
    PADStatus *getUnk08(void) {
        return unk08;
    }
    void setUnk0C(PADStatus *arg0) {
        unk0C = arg0;
    }
    PADStatus *getUnk0C(void) {
        return unk0C;
    }
    u32 getUnk14(void) {
        return unk14;
    }
    bool unkInputCheck(u32 mask) {
        return (((unk08->err == PAD_ERR_NONE)) && (PADButtonDown(unk0C->button, unk08->button) & mask));
    }
private:

    s32 unk04;
    PADStatus *unk08;
    PADStatus *unk0C;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u32 unk14;
};


// TODO: move this somewhere else
template <typename T>
struct Lock {
    Lock(T arg0) {
        inter = OSDisableInterrupts();
    }
    ~Lock(void) {
        OSRestoreInterrupts(inter);
    }

    BOOL inter;
};

class CControllerManager : public TSingleton<CControllerManager> {
public:

    virtual void _08(void);
    virtual ~CControllerManager(void);
    virtual void _10(CController *(s32));
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(void);

    CControllerManager(void);

    CController *fn_801D5FF0(s32 idx);
    CGCController *fn_801D6000(s32 idx);

    void *doAlloc(u32 size) {
        // TODO: doesn't match when using Lock..
        BOOL inter = OSDisableInterrupts();
        void *alloc = MEMAllocFromAllocator(&unk1C, size);
        OSRestoreInterrupts(inter);
        return alloc;
    }

    u8 doFree(void *alloc) {
        Lock<void *> lock(alloc);
        MEMFreeToAllocator(&unk1C, alloc);
        return true;
    }

    CController *getController(s32 idx) { // TODO: inline deferred memes
        return unk04[idx];
    }
private:

    CController *unk04[4];
    CNullController *unk14;
    MEMiHeapHead *unk18;
    MEMAllocator unk1C;
    u8 *unk2C;
    CGCController *unk30[4];
    PADStatus unk40[4];
    PADStatus unk70[4];

    static void *fn_801D5950(u32);
    static u8 fn_801D59B0(void *);
};

extern CControllerManager *gControllerManager;

#endif