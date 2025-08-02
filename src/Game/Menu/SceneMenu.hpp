#ifndef GAME_MENU_SCENEMENU_HPP
#define GAME_MENU_SCENEMENU_HPP

#include <revolution/types.h>
#include "Layout.hpp"
#include "ExScene.hpp"

namespace Menu {

extern s32 sceneVer;

} // namespace Menu

class CSceneMenu : public CExScene {
public:
    virtual ~CSceneMenu(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(void);
    virtual void _20(void);
    virtual void _28(void);

    CSceneMenu(void) {}

    void fn_800077A8(u8);

    SCENE_DECL_CREATE_FN()

    static void fn_80006FA4(void);

private:
    static wchar_t sTextBuffer[1024];
    static wchar_t sEntryNumTextBuffer[16];

    wchar_t mUnk34[64];
    bool mUnkB4;
};

#endif