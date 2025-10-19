#ifndef GAME_EXSCENE_HPP
#define GAME_EXSCENE_HPP

#include <revolution/types.h>

#include "Scene.hpp"

#include "PauseLayout.hpp"

#include "CellAnim.hpp"

class CExScene : public CScene {
public:
    virtual void _08(void);
    virtual ~CExScene(void) {}
    virtual void _10(void) = 0;
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(void);
    virtual void _20(void);
    virtual bool _24(void);
    virtual void _28(void);

    CExScene(void);
    void fn_8000818C(void);

    void fn_80008A20(void);

    void fn_80008FC0(bool, u32);

    bool fn_80009AA0(void);

    static void fn_80009ABC();

protected:
    CPauseLayout *mPauseLayout;
    u32 unk14;
    u32 unk18;
    CCellAnim *unk1C;
    CCellAnim *unk20;
    u8 unk24;
    u8 unk25;
    u32 unk28;
    u16 unk2C;
    u16 unk2E;
    s32 unk30;
};

#endif