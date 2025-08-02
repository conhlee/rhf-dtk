#include "SceneManager.hpp"
#include "GameManager.hpp"
#include "TickFlowManager.hpp"

#include "Menu/SceneMenu.hpp"
#include "Prologue/ScenePrologue.hpp"
#include "Strap/SceneStrap.hpp"
#include "Logo/SceneLogo.hpp"
#include "Credit/SceneCredit.hpp"
#include "AgbGhost/SceneAgbGhost.hpp"

CSceneManager::CSceneManager(void) {

}

CSceneManager::~CSceneManager(void) {
    _08();
}

void CSceneManager::_10(void) {

}

void CSceneManager::_08(void) {

}

void CSceneManager::_14(void) {
    unk404 = 0;
    for (s32 i = 0; i < (s32)ARRAY_LENGTH(mSceneHist); i++) {
        mSceneHist[i] = EScene_Invalid;
    }
}

extern "C" void fn_8008A8D8(void);

void CSceneManager::_18(void) {
    if (unk404) {
        fn_8008A8D8();
        unk404 = 0;
    }
}

// TODO: migrate these functions into their respective scene files
extern "C" void fn_800136F4(void);
extern "C" void fn_800204F0(void);
extern "C" void fn_80022D8C(void);
extern "C" void fn_80027FB8(void);
extern "C" void fn_8002A5B4(void);
extern "C" void fn_8002CF84(void);
extern "C" void fn_80034354(void);
extern "C" void fn_800302A8(void);
extern "C" void fn_80036734(void);
extern "C" void fn_8005CF38(void);
extern "C" void fn_800535D4(void);
extern "C" void fn_80059D3C(void);
extern "C" void fn_8003BE58(void);
extern "C" void fn_800454B0(void);
extern "C" void fn_80056CF0(void);
extern "C" void fn_8005029C(void);
extern "C" void fn_80057D58(void);
extern "C" void fn_8004BE50(void);
extern "C" void fn_80047AEC(void);
extern "C" void fn_8004DDC4(void);
extern "C" void fn_80069814(void);
extern "C" void fn_8006D5C0(void);
extern "C" void fn_800657B4(void);
extern "C" void fn_80060534(void);
extern "C" void fn_8006F390(void);
extern "C" void fn_8006C6DC(void);
extern "C" void fn_800759C4(void);
extern "C" void fn_800B5460(void);
extern "C" void fn_800BC6DC(void);
extern "C" void fn_800B956C(void);
extern "C" void fn_800D7F70(void);
extern "C" void fn_800C6114(void);
extern "C" void fn_8003F2F8(void);
extern "C" void fn_80015AFC(void);
extern "C" void fn_800D5294(void);
extern "C" void fn_800AD4F8(void);
extern "C" void fn_8000F838(void);
extern "C" void fn_80090A54(void);
extern "C" void fn_8001DCD8(void);
extern "C" void fn_800107C0(void);
extern "C" void fn_8009E9C8(void);
extern "C" void fn_800C86EC(void);
extern "C" void fn_800CB2B8(void);
extern "C" void fn_8009D6B4(void);
extern "C" void fn_800A5B24(void);
extern "C" void fn_800A8FB8(void);
extern "C" void fn_800AB9C8(void);
extern "C" void fn_800795D8(void);
extern "C" void fn_80092098(void);
extern "C" void fn_8000EC28(void);
extern "C" void fn_800A4674(void);
extern "C" void fn_8000B4B4(void);
extern "C" void fn_8000C2E4(void);
extern "C" void fn_800CF810(void);
extern "C" void fn_80082FB0(void);
extern "C" void fn_8009B39C(void);
extern "C" void fn_8009A1C8(void);
extern "C" void fn_800B2918(void);
extern "C" void fn_800B3FBC(void);

// ??
const char lbl_803251B8[] = "Menu";
const char lbl_80255710[] = "Badminton";
const char lbl_8025571C[] = "Baseball";
const char lbl_803251C0[] = "Batting";
const char lbl_803251C8[] = "Birds";
const char lbl_803251D0[] = "Bun";
const char lbl_803251D8[] = "Concons";
const char lbl_803251E0[] = "Date";
const char lbl_803251E8[] = "Fishing";
const char lbl_803251F0[] = "Flea";
const char lbl_803251F8[] = "Fork";
const char lbl_80325200[] = "Goma";
const char lbl_80255728[] = "Interview";
const char lbl_80255734[] = "Karateman";
const char lbl_80325208[] = "Muscle";
const char lbl_80325210[] = "Panel";
const char lbl_80325218[] = "Rap";
const char lbl_80325220[] = "Receive";
const char lbl_80325228[] = "Robot";
const char lbl_80325230[] = "Rocket";
const char lbl_80255740[] = "Rotation";
const char lbl_80325238[] = "Samurai";
const char lbl_80325240[] = "Seal";
const char lbl_80325248[] = "Seesaw";
const char lbl_80325250[] = "Shrimp";
const char lbl_80325258[] = "Sort";
const char lbl_8025574C[] = "Tambourine";
const char lbl_80325260[] = "Tap";
const char lbl_80325264[] = "Watch";
const char lbl_8032526C[] = "Alarm";
const char lbl_80325274[] = "Eatmen";
const char lbl_80255758[] = "Metroman";
const char lbl_80255764[] = "Shooting";
const char lbl_8032527C[] = "Boat";
const char lbl_80325284[] = "Kungfu";
const char lbl_8032528C[] = "Omochi";
const char lbl_80325294[] = "Sword";
const char lbl_8032529C[] = "Basket";
const char lbl_80255770[] = "Tutorial";
const char lbl_803252A4[] = "Frog";
const char lbl_803252AC[] = "Choro";
const char lbl_803252B4[] = "Hihat";
const char lbl_803252BC[] = "Mail";
const char lbl_80255780[] = "RhythmFighterVS";
const char lbl_803252C8[] = "AgbClap";
const char lbl_80255790[] = "AgbGhost";
const char lbl_8025579C[] = "AgbKanji";
const char lbl_803252D0[] = "AgbTap";
const char lbl_802557A8[] = "NightWalk";
const char lbl_803252D8[] = "Error";
const char lbl_803252E0[] = "Strap";
const char lbl_803252E8[] = "Logo";
const char lbl_803252F0[] = "Title";
const char lbl_802557B4[] = "GameSelect";
const char lbl_802557C0[] = "BonusSelect";
const char lbl_802557CC[] = "Prologue";
const char lbl_802557D8[] = "Epilogue";
const char lbl_803252F8[] = "Grading";
const char lbl_802557E4[] = "Grading2P";
const char lbl_80325300[] = "Perfect";
const char lbl_80325308[] = "Navi";
const char lbl_80325310[] = "Cafe";
const char lbl_802557F0[] = "CafeMenu";
const char lbl_80325318[] = "Reading";
const char lbl_80325320[] = "Credit";
const char lbl_80325328[] = "XXX";

const char *lbl_802ECE20[] = {
    lbl_803251B8, lbl_80255710, lbl_8025571C, lbl_803251C0, lbl_803251C8, lbl_803251D0, lbl_803251D8, lbl_803251E0, 
    lbl_803251E8, lbl_803251F0, lbl_803251F8, lbl_80325200, lbl_80255728, lbl_80255734, lbl_80325208, lbl_80325210, 
    lbl_80325218, lbl_80325220, lbl_80325228, lbl_80325230, lbl_80255740, lbl_80325238, lbl_80325240, lbl_80325248, 
    lbl_80325250, lbl_80325258, lbl_8025574C, lbl_80325260, lbl_80325264, lbl_8032526C, lbl_80325274, lbl_80255758, 
    lbl_80255764, lbl_8032527C, lbl_80325284, lbl_8032528C, lbl_80325294, lbl_8032529C, lbl_80255770, lbl_803252A4, 
    lbl_803252AC, lbl_803252B4, lbl_803252BC, lbl_80255780, lbl_803252C8, lbl_80255790, lbl_8025579C, lbl_803252D0, 
    lbl_802557A8, lbl_803252D8, lbl_803252E0, lbl_803252E8, lbl_803252F0, lbl_802557B4, lbl_802557C0, lbl_802557CC, 
    lbl_802557D8, lbl_803252F8, lbl_802557E4, lbl_80325300, lbl_80325308, lbl_80325310, lbl_802557F0, lbl_80325318, 
    lbl_80325320, lbl_80325328, 
};

void CSceneManager::fn_80089FE0(eSceneID sceneID, const TickFlowCode *tickFlowCode) {
    CScene::CreateFn fn = NULL;

    switch (sceneID) {
        case EScene_0:
            fn = CSceneMenu::create;
            break;
        case EScene_5:
            fn = (CScene::CreateFn)fn_800136F4;
            break;
        case EScene_4:
            fn = (CScene::CreateFn)fn_800204F0;
            break;
        case EScene_F:
            fn = (CScene::CreateFn)fn_80022D8C;
            break;
        case EScene_7:
            fn = (CScene::CreateFn)fn_80027FB8;
            break;
        case EScene_13:
            fn = (CScene::CreateFn)fn_8002A5B4;
            break;
        case EScene_17:
            fn = (CScene::CreateFn)fn_8002CF84;
            break;
        case EScene_E:
            fn = (CScene::CreateFn)fn_80034354;
            break;
        case EScene_6:
            fn = (CScene::CreateFn)fn_800302A8;
            break;
        case EScene_18:
            fn = (CScene::CreateFn)fn_80036734;
            break;
        case EScene_1B:
            fn = (CScene::CreateFn)fn_8005CF38;
            break;
        case EScene_11:
            fn = (CScene::CreateFn)fn_800535D4;
            break;
        case EScene_19:
            fn = (CScene::CreateFn)fn_80059D3C;
            break;
        case EScene_3:
            fn = (CScene::CreateFn)fn_8003BE58;
            break;
        case EScene_8:
            fn = (CScene::CreateFn)fn_800454B0;
            break;
        case EScene_14:
            fn = (CScene::CreateFn)fn_80056CF0;
            break;
        case EScene_10:
            fn = (CScene::CreateFn)fn_8005029C;
            break;
        case EScene_16:
            fn = (CScene::CreateFn)fn_80057D58;
            break;
        case EScene_A:
            fn = (CScene::CreateFn)fn_8004BE50;
            break;
        case EScene_9:
            fn = (CScene::CreateFn)fn_80047AEC;
            break;
        case EScene_B:
            fn = (CScene::CreateFn)fn_8004DDC4;
            break;
        case EScene_D:
            fn = (CScene::CreateFn)fn_80069814;
            break;
        case EScene_1A:
            fn = (CScene::CreateFn)fn_8006D5C0;
            break;
        case EScene_2:
            fn = (CScene::CreateFn)fn_800657B4;
            break;
        case EScene_1:
            fn = (CScene::CreateFn)fn_80060534;
            break;
        case EScene_1C:
            fn = (CScene::CreateFn)fn_8006F390;
            break;
        case EScene_12:
            fn = (CScene::CreateFn)fn_8006C6DC;
            break;
        case EScene_15:
            fn = (CScene::CreateFn)fn_800759C4;
            break;
        case EScene_C:
            fn = (CScene::CreateFn)fn_800B5460;
            break;
        case EScene_1D:
            fn = (CScene::CreateFn)fn_800BC6DC;
            break;
        case EScene_1E:
            fn = (CScene::CreateFn)fn_800B956C;
            break;
        case EScene_1F:
            fn = (CScene::CreateFn)fn_800D7F70;
            break;
        case EScene_20:
            fn = (CScene::CreateFn)fn_800C6114;
            break;
        case EScene_21:
            fn = (CScene::CreateFn)fn_8003F2F8;
            break;
        case EScene_22:
            fn = (CScene::CreateFn)fn_80015AFC;
            break;
        case EScene_23:
            fn = (CScene::CreateFn)fn_800D5294;
            break;
        case EScene_24:
            fn = (CScene::CreateFn)fn_800AD4F8;
            break;
        case EScene_25:
            fn = (CScene::CreateFn)fn_8000F838;
            break;
        case EScene_26:
            fn = (CScene::CreateFn)fn_80090A54;
            break;
        case EScene_27:
            fn = (CScene::CreateFn)fn_8001DCD8;
            break;
        case EScene_28:
            fn = (CScene::CreateFn)fn_800107C0;
            break;
        case EScene_29:
            fn = (CScene::CreateFn)fn_8009E9C8;
            break;
        case EScene_2A:
            fn = (CScene::CreateFn)fn_800C86EC;
            break;
        case EScene_2B:
            fn = (CScene::CreateFn)fn_800CB2B8;
            break;
        case EScene_2C:
            fn = (CScene::CreateFn)fn_8009D6B4;
            break;
        case EScene_2D:
            fn = CSceneAgbGhost::create;
            break;
        case EScene_2E:
            fn = (CScene::CreateFn)fn_800A5B24;
            break;
        case EScene_2F:
            fn = (CScene::CreateFn)fn_800A8FB8;
            break;
        case EScene_30:
            fn = (CScene::CreateFn)fn_800AB9C8;
            break;
        case EScene_31:
            fn = (CScene::CreateFn)fn_800795D8;
            break;
        case EScene_32:
            fn = CSceneStrap::create;
            break;
        case EScene_33:
            fn = CSceneLogo::create;
            break;
        case EScene_34:
            fn = (CScene::CreateFn)fn_80092098;
            break;
        case EScene_35:
            fn = (CScene::CreateFn)fn_8000EC28;
            break;
        case EScene_36:
            fn = (CScene::CreateFn)fn_800A4674;
            break;
        case EScene_37:
            fn = CScenePrologue::create;
            break;
        case EScene_38:
            fn = (CScene::CreateFn)fn_8000B4B4;
            break;
        case EScene_39:
            fn = (CScene::CreateFn)fn_8000C2E4;
            break;
        case EScene_3A:
            fn = (CScene::CreateFn)fn_800CF810;
            break;
        case EScene_3B:
            fn = (CScene::CreateFn)fn_80082FB0;
            break;
        case EScene_3C:
            fn = (CScene::CreateFn)fn_8009B39C;
            break;
        case EScene_3D:
            fn = (CScene::CreateFn)fn_8009A1C8;
            break;
        case EScene_3E:
            fn = (CScene::CreateFn)fn_800B2918;
            break;
        case EScene_3F:
            fn = (CScene::CreateFn)fn_800B3FBC;
            break;
        case EScene_40:
            fn = CSceneCredit::create;
            break;
    }

    gGameManager->_20(fn, 3);
    gGameManager->_34(tickFlowCode);

    for (int i = ARRAY_LENGTH(mSceneHist) - 1; i > 0; i--) {
        mSceneHist[i] = mSceneHist[i - 1];
    }

    mSceneHist[0] = sceneID;
    if (mSceneHist[1] == EScene_Invalid) {
        OSReport("Scene Change [ NULL ] → [ %s ]\n", lbl_802ECE20[mSceneHist[0]]);
    }
    else {
        OSReport("Scene Change [ %s ] → [ %s ]\n", lbl_802ECE20[mSceneHist[1]], lbl_802ECE20[mSceneHist[0]]);
    }
}


// TODO: migrate these vars into their respective scene files
extern s32 lbl_80320378;
extern s32 lbl_80320380;
extern s32 lbl_80320308;
extern s32 lbl_803202AC;
extern s32 lbl_80320288;
extern s32 lbl_803202D0;
extern s32 lbl_803202B8;
extern s32 lbl_80320328;
extern s32 lbl_80320330;
extern s32 lbl_80320338;
extern s32 lbl_80320340;
extern s32 lbl_80320538;
extern s32 lbl_80320388;
extern s32 lbl_803202D8;
extern s32 lbl_803202B0;
extern s32 lbl_80320348;
extern s32 lbl_80320350;
extern s32 lbl_80320390;
extern s32 lbl_803202C0;
extern s32 lbl_80320358;
extern s32 lbl_803203B0;
extern s32 lbl_80320360;
extern s32 lbl_803202C8;
extern s32 lbl_803202E0;
extern s32 lbl_80320368;
extern s32 lbl_80320398;
extern s32 lbl_80320370;
extern s32 lbl_803203A0;
extern s32 lbl_80320568;
extern s32 lbl_80320540;
extern s32 lbl_803205E8;
extern s32 lbl_80320580;
extern s32 lbl_80320324;
extern s32 lbl_80320290;
extern s32 lbl_803205E0;
extern s32 lbl_80320520;
extern s32 lbl_80320278;
extern s32 lbl_803204A0;
extern s32 lbl_80320298;
extern s32 lbl_80320280;
extern s32 lbl_803204E0;
extern s32 lbl_80320590;
extern s32 lbl_80320598;
extern s32 lbl_803204D0;
extern s32 lbl_80320508;
extern s32 lbl_80320500;
extern s32 lbl_80320510;
extern s32 lbl_80320518;
extern s32 lbl_803203BC;
extern s32 lbl_803204A8;
extern s32 lbl_80320270;
extern s32 lbl_803204F8;
extern s32 lbl_80320250;
extern s32 lbl_80320260;
extern s32 lbl_803205A0;
extern s32 lbl_80320438;
extern s32 lbl_803204C8;
extern s32 lbl_803204B8;
extern s32 lbl_80320528;
extern s32 lbl_80320530;

void CSceneManager::fn_8008A4DC(eSceneID sceneID, u32 ver) {
    switch (sceneID) {
        case EScene_0:
            Menu::sceneVer = ver;
            break;
        case EScene_1:
            lbl_80320378 = ver;
            break;
        case EScene_2:
            lbl_80320380 = ver;
            break;
        case EScene_3:
            lbl_80320308 = ver;
            break;
        case EScene_4:
            lbl_803202AC = ver;
            break;
        case EScene_5:
            lbl_80320288 = ver;
            break;
        case EScene_6:
            lbl_803202D0 = ver;
            break;
        case EScene_7:
            lbl_803202B8 = ver;
            break;
        case EScene_8:
            lbl_80320328 = ver;
            break;
        case EScene_9:
            lbl_80320330 = ver;
            break;
        case EScene_A:
            lbl_80320338 = ver;
            break;
        case EScene_B:
            lbl_80320340 = ver;
            break;
        case EScene_C:
            lbl_80320538 = ver;
            break;
        case EScene_D:
            lbl_80320388 = ver;
            break;
        case EScene_E:
            lbl_803202D8 = ver;
            break;
        case EScene_F:
            lbl_803202B0 = ver;
            break;
        case EScene_10:
            lbl_80320348 = ver;
            break;
        case EScene_11:
            lbl_80320350 = ver;
            break;
        case EScene_12:
            lbl_80320390 = ver;
            break;
        case EScene_13:
            lbl_803202C0 = ver;
            break;
        case EScene_14:
            lbl_80320358 = ver;
            break;
        case EScene_15:
            lbl_803203B0 = ver;
            break;
        case EScene_16:
            lbl_80320360 = ver;
            break;
        case EScene_17:
            lbl_803202C8 = ver;
            break;
        case EScene_18:
            lbl_803202E0 = ver;
            break;
        case EScene_19:
            lbl_80320368 = ver;
            break;
        case EScene_1A:
            lbl_80320398 = ver;
            break;
        case EScene_1B:
            lbl_80320370 = ver;
            break;
        case EScene_1C:
            lbl_803203A0 = ver;
            break;
        case EScene_1D:
            lbl_80320568 = ver;
            break;
        case EScene_1E:
            lbl_80320540 = ver;
            break;
        case EScene_1F:
            lbl_803205E8 = ver;
            break;
        case EScene_20:
            lbl_80320580 = ver;
            break;
        case EScene_21:
            lbl_80320324 = ver;
            break;
        case EScene_22:
            lbl_80320290 = ver;
            break;
        case EScene_23:
            lbl_803205E0 = ver;
            break;
        case EScene_24:
            lbl_80320520 = ver;
            break;
        case EScene_25:
            lbl_80320278 = ver;
            break;
        case EScene_26:
            lbl_803204A0 = ver;
            break;
        case EScene_27:
            lbl_80320298 = ver;
            break;
        case EScene_28:
            lbl_80320280 = ver;
            break;
        case EScene_29:
            lbl_803204E0 = ver;
            break;
        case EScene_2A:
            lbl_80320590 = ver;
            break;
        case EScene_2B:
            lbl_80320598 = ver;
            break;
        case EScene_2C:
            lbl_803204D0 = ver;
            break;
        case EScene_2D:
            lbl_80320508 = ver;
            break;
        case EScene_2E:
            lbl_80320500 = ver;
            break;
        case EScene_2F:
            lbl_80320510 = ver;
            break;
        case EScene_30:
            lbl_80320518 = ver;
            break;
        case EScene_31:
            lbl_803203BC = ver;
            break;
        case EScene_32:
            Strap::sceneVer = ver;
            break;
        case EScene_33:
            Logo::sceneVer = ver;
            break;
        case EScene_34:
            lbl_803204A8 = ver;
            break;
        case EScene_35:
            lbl_80320270 = ver;
            break;
        case EScene_36:
            lbl_803204F8 = ver;
            break;
        case EScene_37:
            Prologue::sceneVer = ver;
            break;
        case EScene_38:
            lbl_80320250 = ver;
            break;
        case EScene_39:
            lbl_80320260 = ver;
            break;
        case EScene_3A:
            lbl_803205A0 = ver;
            break;
        case EScene_3B:
            lbl_80320438 = ver;
            break;
        case EScene_3C:
            lbl_803204C8 = ver;
            break;
        case EScene_3D:
            lbl_803204B8 = ver;
            break;
        case EScene_3E:
            lbl_80320528 = ver;
            break;
        case EScene_3F:
            lbl_80320530 = ver;
            break;
        case EScene_40:
            Credit::sceneVer = ver;
            break;
    }
}


// TODO: migrate these functions into their respective scene files
extern "C" void fn_800606E4(void);
extern "C" void fn_800658F8(void);
extern "C" void fn_8003BEE4(void);
extern "C" void fn_8002055C(void);
extern "C" void fn_80013768(void);
extern "C" void fn_80030434(void);
extern "C" void fn_800281D0(void);
extern "C" void fn_8004553C(void);
extern "C" void fn_80047D08(void);
extern "C" void fn_8004BEB4(void);
extern "C" void fn_8004DE50(void);
extern "C" void fn_800B5508(void);
extern "C" void fn_80069878(void);
extern "C" void fn_800344C0(void);
extern "C" void fn_80022F74(void);
extern "C" void fn_80050340(void);
extern "C" void fn_8005380C(void);
extern "C" void fn_8006C740(void);
extern "C" void fn_8002A770(void);
extern "C" void fn_80056D80(void);
extern "C" void fn_80075A68(void);
extern "C" void fn_80057E80(void);
extern "C" void fn_8002D0B8(void);
extern "C" void fn_80036798(void);
extern "C" void fn_80059EA8(void);
extern "C" void fn_8006D644(void);
extern "C" void fn_8005D04C(void);
extern "C" void fn_8006F4B4(void);
extern "C" void fn_800BC830(void);
extern "C" void fn_800B95F4(void);
extern "C" void fn_800D7FDC(void);
extern "C" void fn_800C6180(void);
extern "C" void fn_8003F550(void);
extern "C" void fn_80015F10(void);
extern "C" void fn_800D5308(void);
extern "C" void fn_800AD578(void);
extern "C" void fn_8000F8A4(void);
extern "C" void fn_80090AD8(void);
extern "C" void fn_8001DD54(void);
extern "C" void fn_80010840(void);
extern "C" void fn_8009EA84(void);
extern "C" void fn_800C8810(void);
extern "C" void fn_800CB354(void);
extern "C" void fn_8009D718(void);
extern "C" void fn_800A5BA4(void);
extern "C" void fn_800A9034(void);
extern "C" void fn_800ABBC8(void);
extern "C" void fn_8007963C(void);
extern "C" void fn_80092104(void);
extern "C" void fn_8000EC8C(void);
extern "C" void fn_800A46D8(void);
extern "C" void fn_8000B518(void);
extern "C" void fn_8000C348(void);
extern "C" void fn_800CF884(void);
extern "C" void fn_80083014(void);
extern "C" void fn_8009B458(void);
extern "C" void fn_8009A22C(void);
extern "C" void fn_800B297C(void);
extern "C" void fn_800B4020(void);

void CSceneManager::fn_8008A704(eSceneID sceneID) {
    switch (sceneID) {
        case EScene_0:
            CSceneMenu::fn_80006FA4();
            break;
        case EScene_1:
            fn_800606E4();
            break;
        case EScene_2:
            fn_800658F8();
            break;
        case EScene_3:
            fn_8003BEE4();
            break;
        case EScene_4:
            fn_8002055C();
            break;
        case EScene_5:
            fn_80013768();
            break;
        case EScene_6:
            fn_80030434();
            break;
        case EScene_7:
            fn_800281D0();
            break;
        case EScene_8:
            fn_8004553C();
            break;
        case EScene_9:
            fn_80047D08();
            break;
        case EScene_A:
            fn_8004BEB4();
            break;
        case EScene_B:
            fn_8004DE50();
            break;
        case EScene_C:
            fn_800B5508();
            break;
        case EScene_D:
            fn_80069878();
            break;
        case EScene_E:
            fn_800344C0();
            break;
        case EScene_F:
            fn_80022F74();
            break;
        case EScene_10:
            fn_80050340();
            break;
        case EScene_11:
            fn_8005380C();
            break;
        case EScene_12:
            fn_8006C740();
            break;
        case EScene_13:
            fn_8002A770();
            break;
        case EScene_14:
            fn_80056D80();
            break;
        case EScene_15:
            fn_80075A68();
            break;
        case EScene_16:
            fn_80057E80();
            break;
        case EScene_17:
            fn_8002D0B8();
            break;
        case EScene_18:
            fn_80036798();
            break;
        case EScene_19:
            fn_80059EA8();
            break;
        case EScene_1A:
            fn_8006D644();
            break;
        case EScene_1B:
            fn_8005D04C();
            break;
        case EScene_1C:
            fn_8006F4B4();
            break;
        case EScene_1D:
            fn_800BC830();
            break;
        case EScene_1E:
            fn_800B95F4();
            break;
        case EScene_1F:
            fn_800D7FDC();
            break;
        case EScene_20:
            fn_800C6180();
            break;
        case EScene_21:
            fn_8003F550();
            break;
        case EScene_22:
            fn_80015F10();
            break;
        case EScene_23:
            fn_800D5308();
            break;
        case EScene_24:
            fn_800AD578();
            break;
        case EScene_25:
            fn_8000F8A4();
            break;
        case EScene_26:
            fn_80090AD8();
            break;
        case EScene_27:
            fn_8001DD54();
            break;
        case EScene_28:
            fn_80010840();
            break;
        case EScene_29:
            fn_8009EA84();
            break;
        case EScene_2A:
            fn_800C8810();
            break;
        case EScene_2B:
            fn_800CB354();
            break;
        case EScene_2C:
            fn_8009D718();
            break;
        case EScene_2D:
            CSceneAgbGhost::fn_800A772C();
            break;
        case EScene_2E:
            fn_800A5BA4();
            break;
        case EScene_2F:
            fn_800A9034();
            break;
        case EScene_30:
            fn_800ABBC8();
            break;
        case EScene_31:
            fn_8007963C();
            break;
        case EScene_32:
            CSceneStrap::fn_8007B2D8();
            break;
        case EScene_33:
            CSceneLogo::fn_800A0BC4();
            break;
        case EScene_34:
            fn_80092104();
            break;
        case EScene_35:
            fn_8000EC8C();
            break;
        case EScene_36:
            fn_800A46D8();
            break;
        case EScene_37:
            CScenePrologue::fn_8000AD98();
            break;
        case EScene_38:
            fn_8000B518();
            break;
        case EScene_39:
            fn_8000C348();
            break;
        case EScene_3A:
            fn_800CF884();
            break;
        case EScene_3B:
            fn_80083014();
            break;
        case EScene_3C:
            fn_8009B458();
            break;
        case EScene_3D:
            fn_8009A22C();
            break;
        case EScene_3E:
            fn_800B297C();
            break;
        case EScene_3F:
            fn_800B4020();
            break;
        case EScene_40:
            CSceneCredit::fn_800C42AC();
            break;
    }
}


// TODO: migrate these functions into their respective scene files
extern "C" void fn_800607D0(void);
extern "C" void fn_80065A94(void);
extern "C" void fn_8003BFD0(void);
extern "C" void fn_800208B4(void);
extern "C" void fn_80013880(void);
extern "C" void fn_800305AC(void);
extern "C" void fn_800282E8(void);
extern "C" void fn_800456B4(void);
extern "C" void fn_80047E24(void);
extern "C" void fn_8004BFD0(void);
extern "C" void fn_8004DF40(void);
extern "C" void fn_800B5624(void);
extern "C" void fn_800699C0(void);
extern "C" void fn_80034618(void);
extern "C" void fn_800230B8(void);
extern "C" void fn_800504DC(void);
extern "C" void fn_80053994(void);
extern "C" void fn_8006C8DC(void);
extern "C" void fn_8002A88C(void);
extern "C" void fn_80056F50(void);
extern "C" void fn_80075B80(void);
extern "C" void fn_80057F98(void);
extern "C" void fn_8002D230(void);
extern "C" void fn_800369B8(void);
extern "C" void fn_8005A078(void);
extern "C" void fn_8006D760(void);
extern "C" void fn_8005D13C(void);
extern "C" void fn_8006F62C(void);
extern "C" void fn_800B96BC(void);
extern "C" void fn_800D80A4(void);
extern "C" void fn_8003F690(void);
extern "C" void fn_8000F954(void);
extern "C" void fn_80090B88(void);
extern "C" void fn_8001DE04(void);

void CSceneManager::fn_8008A82C(eSceneID sceneID) {
    switch (sceneID) {
        case EScene_0:
            break;
        case EScene_1:
            fn_800607D0();
            break;
        case EScene_2:
            fn_80065A94();
            break;
        case EScene_3:
            fn_8003BFD0();
            break;
        case EScene_4:
            fn_800208B4();
            break;
        case EScene_5:
            fn_80013880();
            break;
        case EScene_6:
            fn_800305AC();
            break;
        case EScene_7:
            fn_800282E8();
            break;
        case EScene_8:
            fn_800456B4();
            break;
        case EScene_9:
            fn_80047E24();
            break;
        case EScene_A:
            fn_8004BFD0();
            break;
        case EScene_B:
            fn_8004DF40();
            break;
        case EScene_C:
            fn_800B5624();
            break;
        case EScene_D:
            fn_800699C0();
            break;
        case EScene_E:
            fn_80034618();
            break;
        case EScene_F:
            fn_800230B8();
            break;
        case EScene_10:
            fn_800504DC();
            break;
        case EScene_11:
            fn_80053994();
            break;
        case EScene_12:
            fn_8006C8DC();
            break;
        case EScene_13:
            fn_8002A88C();
            break;
        case EScene_14:
            fn_80056F50();
            break;
        case EScene_15:
            fn_80075B80();
            break;
        case EScene_16:
            fn_80057F98();
            break;
        case EScene_17:
            fn_8002D230();
            break;
        case EScene_18:
            fn_800369B8();
            break;
        case EScene_19:
            fn_8005A078();
            break;
        case EScene_1A:
            fn_8006D760();
            break;
        case EScene_1B:
            fn_8005D13C();
            break;
        case EScene_1C:
            fn_8006F62C();
            break;
        case EScene_1D:
            break;
        case EScene_1E:
            fn_800B96BC();
            break;
        case EScene_1F:
            fn_800D80A4();
            break;
        case EScene_20:
            break;
        case EScene_21:
            fn_8003F690();
            break;
        case EScene_22:
            break;
        case EScene_23:
            break;
        case EScene_24:
            break;
        case EScene_25:
            fn_8000F954();
            break;
        case EScene_26:
            fn_80090B88();
            break;
        case EScene_27:
            fn_8001DE04();
            break;
    }
}

extern "C" bool fn_80009FB4(void);

// TODO: migrate tickflow into respective files
TFD_EXTERN(lbl_80253E18)
TFD_EXTERN(lbl_8027C3E8)
TFD_EXTERN(lbl_8027C424)
TFD_EXTERN(lbl_8027C460)
TFD_EXTERN(lbl_8027C49C)
TFD_EXTERN(lbl_80256F30)

void CSceneManager::fn_8008A8D8(void) {
    gTickFlowManager->fn_801E1E4C();

    bool temp_r31 = false;
    bool temp_r30 = false;
    bool temp_r29 = false;
    bool temp_r28 = false;

    if (mSceneHist[0] == EScene_3C) {
        s32 i = sceneIdx(EScene_35);
        s32 j = sceneIdx(EScene_3D);

        if ((i >= 1) && (j >= 1)) {
            if (i < j) {
                temp_r31 = true;
            }
            else if (j < i) {
                temp_r29 = true;
            }
        }
        else if (i >= 1) {
            temp_r31 = true;
        }
        else if (j >= 1) {
            temp_r29 = true;
        }
        else {
            temp_r28 = true;
        }
    }
    else if ((mSceneHist[0] == EScene_34) || (mSceneHist[0] == EScene_35)) {
        temp_r28 = true;
    }
    else {
        if (fn_80009FB4()) {
            temp_r29 = true;
        }
        else {
            s32 i = sceneIdx(EScene_35);
            s32 j = sceneIdx(EScene_36);

            if ((i >= 1) && (j >= 1)) {
                if (i < j) {
                    temp_r31 = true;
                } else if (j < i) {
                    temp_r30 = true;
                }
            } else if (i >= 1) {
                temp_r31 = true;
            } else if (j >= 1) {
                temp_r30 = true;
            } else {
                temp_r28 = true;
            }
        }
    }

    if (temp_r31) {
        gTickFlowManager->fn_801E1CC0(lbl_80253E18);
    }
    else if (temp_r30) {
        switch (lbl_803204F8) {
        case 0:
            gTickFlowManager->fn_801E1CC0(lbl_8027C3E8);
            break;
        case 1:
            gTickFlowManager->fn_801E1CC0(lbl_8027C424);
            break;
        case 2:
            gTickFlowManager->fn_801E1CC0(lbl_8027C460);
            break;
        case 5:
            gTickFlowManager->fn_801E1CC0(lbl_8027C49C);
            break;
        }
    }
    else if (temp_r29) {
        gTickFlowManager->fn_801E1CC0(lbl_80256F30);
    }
    else if (temp_r28) {
        OSReport("Invalid Scene Change 0002\n");
    }
}

u32 CSceneManager::fn_8008B058(s32 idx) {
    return mSceneHist[idx];
}

void CSceneManager::fn_8008B068(void) {
    for (s32 i = 0; i < (s32)ARRAY_LENGTH(mSceneHist); i++) {
        mSceneHist[i] = EScene_Invalid;
    }
}

bool CSceneManager::fn_8008B0FC(s32 idx, u32 sceneID) {
    return mSceneHist[idx] == sceneID;
}

bool CSceneManager::fn_8008B118(eSceneID sceneID) {
    return sceneIdx(sceneID) >= 0;
}

bool CSceneManager::fn_8008B27C(void) {
    if (lbl_80320274) {
        return false;
    }

    if (gSceneManager->sceneIdx(EScene_35) < 0) {
        return false;
    }
    s32 i = sceneIdx(EScene_35);
    s32 j = sceneIdx(EScene_36);
    if ((j != -1) && (j < i)) {
        return false;
    }

    s32 k = sceneIdx(EScene_40);
    if ((k != -1) && (k < i)) {
        return false;
    }

    return true;
}
