#ifndef GAMEUTIL_CTICKFLOWMANAGER_HPP
#define GAMEUTIL_CTICKFLOWMANAGER_HPP

#include <revolution/types.h>
#include "Singleton.hpp"

#include "TickFlow.hpp"

#include "TickFlowDecl.hpp"

class CTickFlowManager : public TSingleton<CTickFlowManager> {
public:
    virtual void _08(void);
    virtual ~CTickFlowManager(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(CTickFlow::CreateFn, u32);

    template <typename T>
    void registerFlow() {
        _1C(&T::create, sizeof(T));
    }

    void fn_801E1E4C(void);
    void fn_801E1CC0(const TickFlowCode *code, f32 initRest = 0.0f);
    f32 fn_801E2698(void);
    f32 fn_801E2CA8(void);
    bool fn_801E4178(void);

    u8 getUnk6D(void) {
        return unk6D;
    }

private:
    u8 pad04[0x1c-0x04];
    s32 unk1C;
    u8 pad20[0x6C-0x20];
    u8 unk6C;
    u8 unk6D;
};


extern CTickFlowManager *gTickFlowManager;

#endif