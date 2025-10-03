#ifndef GAMEUTIL_GAMEMANAGER_HPP
#define GAMEUTIL_GAMEMANAGER_HPP

#include <revolution/types.h>
#include <revolution/macros.h>

#include "Singleton.hpp"

#include <nw4r/ut.h>

#include "Scene.hpp"

#include "FaderFlash.hpp"

#include "TickFlowDecl.hpp"

class CGameManager : public TSingleton<CGameManager> {
public:
    virtual void _08(void);
    virtual ~CGameManager(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(CScene::CreateFn initSceneCreateFn, CFaderFlash *fader, u16 initSceneHeapGroup);
    virtual void _20(CScene::CreateFn sceneCreateFn, u16 heapGroup);
    virtual void _24(CFaderFlash *fader);
    virtual void _28(void);
    virtual bool _2C(void);
    virtual bool _30(void) {
        return mFader->getUnk04() == 0;   
    }
    virtual void _34(const TickFlowCode *tickFlowCode) {
        mNextTickFlowCode = tickFlowCode;
    }

    CGameManager(void);

    template <typename T>
    void startMainLoop(void) {
        CFaderFlash *fader = CFaderFlash::fn_80007C28();
        _1C(T::create, fader, eHeapGroup_Scene);
    }

    CScene *getCurrentScene(void) const { return mCurrentScene; }

    template <typename T>
    T *getCurrentScene(void) const {
        return static_cast<T *>(getCurrentScene());
    }

    static void fn_801D7538(s32 driveStatus);

private:
    struct DVDMessageData {
        nw4r::ut::ResFont font;
        wchar_t *messageStr;

        ~DVDMessageData(void);

        void fn_801D77A4();
        void DONT_INLINE fn_801D7A74();
    };
    static DVDMessageData sDVDMessageData;

    static bool sIsPowerOff;
    static void osPowerCallback(void);

    static bool sIsReset;
    static void osResetCallback(void);

    CScene *mCurrentScene;
    CScene::CreateFn mNextSceneCreateFunc;
    u16 mNextSceneHeapGroup;
    CFaderFlash *mFader;
    const TickFlowCode *mNextTickFlowCode;
};

extern CGameManager *gGameManager;

#endif 