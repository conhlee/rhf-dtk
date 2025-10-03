#ifndef GAMEUTIL_SCENEMANAGER_HPP
#define GAMEUTIL_SCENEMANAGER_HPP

#include <revolution/types.h>
#include <revolution/OS/OSError.h>

#include "Singleton.hpp"

#include "ExFlowDecl.hpp"

enum eSceneID { // TODO: move this somewhere else
    EScene_0 = 0,
    EScene_1,
    EScene_2,
    EScene_3,
    EScene_4,
    EScene_5,
    EScene_6,
    EScene_7,
    EScene_8,
    EScene_9,
    EScene_A,
    EScene_B,
    EScene_C,
    EScene_D,
    EScene_E,
    EScene_F,
    EScene_10,
    EScene_11,
    EScene_12,
    EScene_13,
    EScene_14,
    EScene_15,
    EScene_16,
    EScene_17,
    EScene_18,
    EScene_19,
    EScene_1A,
    EScene_1B,
    EScene_1C,
    EScene_1D,
    EScene_1E,
    EScene_1F,
    EScene_20,
    EScene_21,
    EScene_22,
    EScene_23,
    EScene_24,
    EScene_25,
    EScene_26,
    EScene_27,
    EScene_28,
    EScene_29,
    EScene_2A,
    EScene_2B,
    EScene_2C,
    EScene_2D,
    EScene_2E,
    EScene_2F,
    EScene_30,
    EScene_31,
    EScene_32,
    EScene_33,
    EScene_34,
    EScene_35,
    EScene_36,
    EScene_37,
    EScene_38,
    EScene_39,
    EScene_3A,
    EScene_3B,
    EScene_3C,
    EScene_3D,
    EScene_3E,
    EScene_3F,
    EScene_40,
    EScene_Invalid = -1,
};

class CSceneManager : public TSingleton<CSceneManager> {
public:
    virtual void _08(void);
    virtual ~CSceneManager(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);

    CSceneManager(void);

    void fn_80089FE0(eSceneID sceneID, const TickFlowCode *tickFlowCode);
    void fn_8008A4DC(eSceneID sceneID, u32 ver);
    void fn_8008A704(eSceneID sceneID);
    void fn_8008A82C(eSceneID sceneID);
    void fn_8008A8D8(void);
    u32 fn_8008B058(s32 idx);
    void fn_8008B068(void);
    bool fn_8008B0FC(s32 idx, u32 sceneID);
    bool fn_8008B118(eSceneID sceneID);
    bool fn_8008B27C(void);

    s32 sceneIdx(eSceneID sceneID) {
        int i;

        for (i = 0; i < ARRAY_LENGTH(mSceneHist); i++) {
            if (mSceneHist[i] == sceneID) {
                return i;
            }
            if (mSceneHist[i] == EScene_Invalid) { // end of scene stack?
                return -1;
            }
        }
        return -1; // did not find the scene
    }

private:
    u32 mSceneHist[0x100];
    u8 unk404;
};

extern bool lbl_80320274;

extern CSceneManager *gSceneManager;


#endif