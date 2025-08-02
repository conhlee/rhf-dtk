#ifndef GAMEUTIL_CFILEMANAGER_HPP
#define GAMEUTIL_CFILEMANAGER_HPP

#include <revolution/types.h>
#include <revolution/DVD.h>
#include <revolution/ARC.h>
#include "Mem.hpp"
#include "Singleton.hpp"

class CFileManager : public TSingleton<CFileManager> {
public:
    virtual void _08(void);
    virtual ~CFileManager(void);
    virtual void _10(s32, s32);
    virtual void _14(void);

    CFileManager(void);

    void fn_801D3C2C(const char *file);
    char *fn_801D3C44(void);
    void *fn_801D3C4C(const char *file, EHeapMEM heap, s32 alignment);
    bool fn_801D3D58(void);
    void fn_801D3D94(void);
    void fn_801D3E94(void);
    void fn_801D3F94(s32 idx, const char *file, EHeapMEM heap, s32 alignment);
    void fn_801D412C(s32 result, DVDFileInfo *fileInfo);
    void fn_801D41CC(s32 idx);
    u32 fn_801D422C(s32 idx, const char *file);
    void *fn_801D4270(s32 idx, const char *file);
    void *fn_801D42CC(s32 idx);
    bool fn_801D42E0(s32 idx);
    bool fn_801D42FC(s32 idx);
    bool fn_801D431C(void);
    void fn_801D4364(s32 idx);
    void fn_801D443C(void);
    void fn_801D4544(void);
    void fn_801D49D4(void);

    static void *fn_801D461C(void *, BOOL, EHeapMEM, s32);

    s32 getFileInfoIdx(DVDFileInfo* fileInfo) {
        s32 index = -1;
        for (s32 i = 0; i < mFileCount; i++) {
            if ((mDvdFileInfo + i) == fileInfo) {
                index = i;
                break;
            }
        }
        return index;
    }

private:
    static void fn_801D392C(s32, DVDFileInfo *); // DVDAsyncCallback
    static void fn_801D3988(s32, DVDFileInfo *); // DVDAsyncCallback

    static void *fn_801D46A4(void *, BOOL, s32, EHeapMEM, s32);
    static void *fn_801D47B8(void *);
    static bool fn_801D47F8(u8 *src, u8 *dst, u32 srcSize, u32 dstSize, s32 idx, BOOL deleteSrc);

private:
    enum EArchiveInfoState {
        eArchiveInfoState_Free = 0,          // Slot is unassigned and available.
        eArchiveInfoState_Loading = 1,       // Waiting for DVD read ..
        eArchiveInfoState_Loaded = 2,        // Waiting for decompression to start ..
        eArchiveInfoState_Decompressing = 3, // Waiting for decompression to finish ..
        eArchiveInfoState_Decompressed = 4,  // Waiting for ARCInitHandle ..
        eArchiveInfoState_Ready = 5          // Ready for access.
    };

    struct ArchiveInfo {
        DVDFileInfo *mDvdFileInfo;
        ARCHandle mArcHandle;
        u8 *mArcData;
        EHeapMEM mHeapMode;
        u16 mHeapId;
        bool mIsCompressed;
        EArchiveInfoState mState;
    };

    struct UnusedFileSub {
        u8 _pad00[0x44];
    };

    static char sFilePathBuffer[64];

    char mLocaleDir[4];

    s32 mFileCount;
    DVDFileInfo *mDvdFileInfo; // DVDFileInfo[mFileCount]
    UnusedFileSub *mUnusedFileSub; // UnusedFileSub[mFileCount]
    bool* mDvdFileInfoActive; // bool[mFileCount]; describes if a mDvdFileInfo slot at the specified index is in use

    s32 mArchiveInfoCount;
    ArchiveInfo *mArchiveInfo; // ArchiveInfo[mArchiveInfoCount]

    u8 _pad20[0x10];

    OSThread mThread;
    u32 *mThreadStack;
    void (*unk34C)(void);
    void (*unk350)(void);
};

extern CFileManager *gFileManager;

#endif
