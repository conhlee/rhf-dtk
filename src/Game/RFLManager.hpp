#ifndef GAME_RFLMANAGER_HPP
#define GAME_RFLMANAGER_HPP

#include <revolution/types.h>

#include <revolution/GX.h>

#include <RVLFaceLibrary.h>

#include "Singleton.hpp"

class CRFLManager : public TSingleton<CRFLManager> {
public:
    virtual void _08(void);
    virtual ~CRFLManager(void);
    virtual void _10(void);

    CRFLManager(void);

    void fn_800C2C40(void);
    void fn_800C2C98(void);
    RFLErrcode fn_800C2CA4(void);
    void fn_800C2E04(void);
    RFLErrcode fn_800C2FBC(void);
    s32 fn_800C2FC4(void);
    GXTexObj *fn_800C2FCC(s32 index);
    GXTexObj *fn_800C2FE0(RFLCreateID createID);
    RFLCreateID fn_800C3060(s32 index);

private:
    RFLErrcode fn_800C2E44(u16 dataIndex, BOOL favorite);

private:
    struct Icon {
        void *texData; // RGB5A3
        GXTexObj texObj;
        RFLCreateID createID;
    };

private:
    enum { MAX_ICON_COUNT = 100 };
    enum { ICON_WIDTH = 128, ICON_HEIGHT = 128 };

private:
    void *mRFLWorkMem;
    RFLErrcode mLastRFLErr;

    Icon *mIcons;
    s32 mIconCount;
    bool mIconsInitialized;
};

extern CRFLManager *gRFLManager;

#endif
