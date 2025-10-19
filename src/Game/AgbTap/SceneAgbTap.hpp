#ifndef GAME_AGBTAP_SCENEAGBTAP_HPP
#define GAME_AGBTAP_SCENEAGBTAP_HPP

#include <revolution/types.h>

#include "ExScene.hpp"

#include "CellAnim.hpp"

#include "TimeRatio.hpp"

namespace AgbTap {

class CMyFlow; // Forward-declaration
class CMyChecker; // Forward-declaration

extern s32 sceneVer;

} // namespace AgbTap

class CSceneAgbTap : public CExScene {
    friend class AgbTap::CMyFlow;
    friend class AgbTap::CMyChecker;

public:
    enum EAnimeType {
        eAnimeType_Ready_L,
        eAnimeType_Ready_R,
        eAnimeType_Tap_1L_NG, // ?
        eAnimeType_Tap_1R_NG, // ?
        eAnimeType_Tap_0L,
        eAnimeType_Tap_0R,
        eAnimeType_Tap_1L,
        eAnimeType_Tap_1R,
        eAnimeType_Charge,
        eAnimeType_Crouch,
        eAnimeType_Jump,
        eAnimeType_Jump_Last,
        eAnimeType_Pause,
        eAnimeType_Round,
        eAnimeType_Land,
        eAnimeType_Ready_2, // SFX only
        eAnimeType_Ready_3_2, // SFX only

        eAnimeType_Null = 18
    };

public:
    virtual ~CSceneAgbTap(void) {}
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(void);
    virtual void _20(void);
    virtual bool _24(void);
    virtual void _28(void);

    CSceneAgbTap(void) {}

    SCENE_DECL_CREATE_FN()

    void fn_800A9698(u32 button, s32 type);

    void fn_800A9758(void);

    void fn_800A9768(void);
    
    void fn_800A97DC(EAnimeType type);

    void fn_800A9924(void);

    void fn_800A9988(EAnimeType type);

    void fn_800A9B20(bool param_1);

    void fn_800A9C3C(void);

    void fn_800A9C84(u32 param_1);

    void fn_800A9D20(void);

    void fn_800A9D90(void);

    void fn_800A9E24(void);

    static void fn_800A8FA4(u32 button);

    static void fn_800A9034(void);

private:
    CCellAnim *mGirlAnim;
    CCellAnim *mMonkeyAnim[2];
    CCellAnim *mGiraffeAnim;

    EAnimeType mLastAnimeType;
    u16 mGirlAnimeTimer;
    u16 mMonkeyAnimeTimer;
    u16 mGiraffeAnimeTimer;

    CTRParabola mGirlPos;
    CTRParabola mMonkeyPos;
    CTRParabola mGiraffePos;

    s32 mUnk158;
    s32 mUnk15C;
};

#endif