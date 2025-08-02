#include "FileManager.hpp"

#include "GameManager.hpp"

#include <string.h>
#include <stdio.h>

char CFileManager::sFilePathBuffer[64];

void CFileManager::fn_801D392C(s32 result, DVDFileInfo *fileInfo) {
    s32 index = gFileManager->getFileInfoIdx(fileInfo);
    if (result == -1) {
        return;
    }
    gFileManager->mDvdFileInfoActive[index] = false;
}

void CFileManager::fn_801D3988(s32 result, DVDFileInfo *fileInfo) {
    gFileManager->fn_801D412C(result, fileInfo);
}

CFileManager::CFileManager(void) {}
CFileManager::~CFileManager(void) {
    _08();
}

#define THREAD_STACK_SIZE (0xA00)

void CFileManager::_10(s32 fileCount, s32 archiveCount) {
    mArchiveInfoCount = archiveCount;
    mFileCount = fileCount;

    mDvdFileInfo = new (eHeap_MEM2, 32) DVDFileInfo[mFileCount];
    mUnusedFileSub = new (eHeap_MEM2, 32) UnusedFileSub[mFileCount];
    mDvdFileInfoActive = new (eHeap_MEM2, 32) bool[mFileCount];
    mArchiveInfo = new (eHeap_MEM2, 32) ArchiveInfo[mArchiveInfoCount];
    mThreadStack = new (eHeap_MEM2, 32) u32[THREAD_STACK_SIZE];
}

void CFileManager::_08(void) {
    delete[] mDvdFileInfo;
    delete[] mUnusedFileSub;
    delete[] mDvdFileInfoActive;
    delete[] mArchiveInfo;
}

void CFileManager::_14(void) {
    DVDInit();
    for (s32 i = 0; i < mFileCount; i++) {
        mDvdFileInfoActive[i] = false;
    }
    for (s32 i = 0; i < mArchiveInfoCount; i++) {
        mArchiveInfo[i].mDvdFileInfo = NULL;
        mArchiveInfo[i].mArcData = NULL;
        mArchiveInfo[i].mState = eArchiveInfoState_Free;
    }
    unk34C = 0;
    unk350 = 0;
}

void CFileManager::fn_801D3C2C(const char *localeDir) {
    sprintf(mLocaleDir, "%s", localeDir);
}

char *CFileManager::fn_801D3C44(void) {
    return mLocaleDir;
}

void *CFileManager::fn_801D3C4C(const char *file, EHeapMEM heap, s32 alignment) {
    sprintf(sFilePathBuffer, "%s%s", gFileManager->fn_801D3C44(), file);
    s32 dfiIndex = -1;
    for (s32 i = 0; i < mFileCount; i++) {
        if (mDvdFileInfoActive[i] == false) {
            dfiIndex = i;
            break;
        }
    }

    DVDOpen(sFilePathBuffer, &mDvdFileInfo[dfiIndex]);

    s32 size = ROUND_UP(mDvdFileInfo[dfiIndex].length, 32);
    void *alloc = new (heap, alignment) u8[size];
    DCInvalidateRange(alloc, size);

    DVDReadAsyncPrio(&mDvdFileInfo[dfiIndex], alloc, size, 0, CFileManager::fn_801D392C, 2);
    mDvdFileInfoActive[dfiIndex] = true;

    return alloc;
}

bool CFileManager::fn_801D3D58(void) {
    for (s32 i = 0; i < mFileCount; i++) {
        if (mDvdFileInfoActive[i]) {
            return true;
        }
    }
    return false;
}

static inline void runArcUpdateTick() {
    gFileManager->fn_801D49D4();
    gFileManager->fn_801D4544();
    OSSleepTicks(OS_MSEC_TO_TICKS(10ll));
}

void CFileManager::fn_801D3D94(void) {
    while (fn_801D3D58()) {
        runArcUpdateTick();
    }
}

void CFileManager::fn_801D3E94(void) {
    while (fn_801D3D58()) {
        runArcUpdateTick();
    }
}

void CFileManager::fn_801D3F94(s32 idx, const char *file, EHeapMEM heap, s32 alignment) {
    sprintf(sFilePathBuffer, "%s%s", gFileManager->fn_801D3C44(), file);

    s32 dfiIndex = -1;
    for (s32 i = 0; i < mFileCount; i++) {
        if (mDvdFileInfoActive[i] == false) {
            dfiIndex = i;
            break;
        }
    }

    mArchiveInfo[idx].mDvdFileInfo = &mDvdFileInfo[dfiIndex];
    mArchiveInfo[idx].mHeapMode = heap;
    mArchiveInfo[idx].mHeapId = fn_801D363C();

    const char *szsExtension = ".szs";
    mArchiveInfo[idx].mIsCompressed = strstr(sFilePathBuffer, szsExtension) != 0;

    mArchiveInfo[idx].mState = eArchiveInfoState_Loading;

    DVDOpen(sFilePathBuffer, &mDvdFileInfo[dfiIndex]);

    u32 size = ROUND_UP(mDvdFileInfo[dfiIndex].length, 32);
    mArchiveInfo[idx].mArcData = new (mArchiveInfo[idx].mHeapMode, alignment) u8[size];
    DCInvalidateRange(mArchiveInfo[idx].mArcData, size);

    DVDReadAsyncPrio(&mDvdFileInfo[dfiIndex], mArchiveInfo[idx].mArcData, size, 0, CFileManager::fn_801D3988, 2);
    mDvdFileInfoActive[dfiIndex] = true;
}

void CFileManager::fn_801D412C(s32 result, DVDFileInfo *fileInfo) {
    // NOTE: doesn't match with inlined ver
    s32 dfiIndex = -1;
    for (s32 i = 0; i < mFileCount; i++) {
        if ((mDvdFileInfo + i) == fileInfo) {
            dfiIndex = i;
            break;
        }
    }

    if (result == DVD_RESULT_FATAL_ERROR) {
        return;
    }

    mDvdFileInfoActive[dfiIndex] = false;
    for (s32 i = 0; i < mArchiveInfoCount; i++) {
        if (mArchiveInfo[i].mDvdFileInfo == fileInfo) {
            mArchiveInfo[i].mState = eArchiveInfoState_Loaded;
            return;
        }
    }
}

void CFileManager::fn_801D41CC(s32 idx) {
    delete[] mArchiveInfo[idx].mArcData;
    mArchiveInfo[idx].mArcData = NULL;
    mArchiveInfo[idx].mState = eArchiveInfoState_Free;
}

u32 CFileManager::fn_801D422C(s32 idx, const char *file) {
    ARCFileInfo fileInfo;
    ARCOpen(&mArchiveInfo[idx].mArcHandle, file, &fileInfo);

    u32 length = ARCGetLength(&fileInfo);

    // ARCClose(&fileInfo); // BUG: ARCClose missing here
    return length;
}

void *CFileManager::fn_801D4270(s32 idx, const char *file) {
    ARCFileInfo fileInfo;
    ARCOpen(&mArchiveInfo[idx].mArcHandle, file, &fileInfo);

    void *startAddr = ARCGetStartAddrInMem(&fileInfo);

    ARCClose(&fileInfo);
    return startAddr;
}

void *CFileManager::fn_801D42CC(s32 idx) {
    return mArchiveInfo[idx].mArcData;
}

bool CFileManager::fn_801D42E0(s32 idx) {
    return mArchiveInfo[idx].mState == eArchiveInfoState_Free;
}

bool CFileManager::fn_801D42FC(s32 idx) {
    return mArchiveInfo[idx].mState == eArchiveInfoState_Ready;
}

bool CFileManager::fn_801D431C(void) {
    bool isIdle = true;
    for (s32 i = 0; i < mFileCount; i++) {
        if ((mArchiveInfo[i].mState != eArchiveInfoState_Free) && (mArchiveInfo[i].mState != eArchiveInfoState_Ready)) {
            isIdle = false;
        }
    }
    return isIdle;
}

void CFileManager::fn_801D4364(s32 idx) {
    while (mArchiveInfo[idx].mState != eArchiveInfoState_Ready) {
        runArcUpdateTick();
    }
}

void CFileManager::fn_801D443C(void) {
    while (!fn_801D431C()) {
        runArcUpdateTick();
    }
}

void CFileManager::fn_801D4544(void) {
    for (s16 i = 0; i < mArchiveInfoCount; i++) {
        ArchiveInfo* archiveInfo = &mArchiveInfo[i];
        bool isArchiveReady = false;

        if (archiveInfo->mState == eArchiveInfoState_Loaded) {
            if (archiveInfo->mIsCompressed) {
                // NOTE: this gets the decompressed buffer before the decompression is actually finished.
                //       if NULL is returned, the decompression thread is still busy; we'll try again next frame.
                void *decompressed = fn_801D46A4(archiveInfo->mArcData, TRUE, i, archiveInfo->mHeapMode, -32);
                if (decompressed) {
                    archiveInfo->mArcData = (u8 *)decompressed;
                    archiveInfo->mState = eArchiveInfoState_Decompressing;
                }
            }
            else {
                isArchiveReady = true;
            }
        }
        else if (archiveInfo->mState == eArchiveInfoState_Decompressed) {
            isArchiveReady = true;
        }

        if (isArchiveReady) {
            ARCInitHandle(archiveInfo->mArcData, &archiveInfo->mArcHandle);
            archiveInfo->mDvdFileInfo = NULL;
            archiveInfo->mState = eArchiveInfoState_Ready;
        }
    }
}

#define getSZSExpandSize(src) ( \
    (((u8 *)(src))[4] << 24) | (((u8 *)(src))[5] << 16) | \
    (((u8 *)(src))[6] << 8) | (((u8 *)(src))[7] << 0) \
)

void *CFileManager::fn_801D461C(void *data, BOOL deleteSrc, EHeapMEM heap, s32 alignment) {
    s32 expandSize = getSZSExpandSize(data);

    u32 dstSize = ROUND_UP(expandSize, 32);
    void *dst = new (heap, alignment) u8[dstSize];

    fn_801D47F8((u8 *)data, (u8 *)dst, expandSize, dstSize, -1, deleteSrc);
    return dst;
}

struct DecompThreadData {
    void *src;
    void *dst;
    u32 expandSize;
    u32 dstSize;
    s16 arcInfoIdx; // Index into gFileManager->mArchiveInfo.
    u8 deleteSrc; // If nonzero, src will be deleted when decompression finishes.
};
static DecompThreadData sDecompThreadData;

void *CFileManager::fn_801D46A4(void *data, BOOL deleteSrc, s32 arcInfoIdx, EHeapMEM heap, s32 alignment) {
    BOOL threadInactive = OSIsThreadTerminated(&gFileManager->mThread);
    if (threadInactive) {
        u32 expandSize = getSZSExpandSize(data);
        u32 dstSize = ROUND_UP(expandSize, 32);

        if (arcInfoIdx >= 0) {
            fn_801D369C(gFileManager->mArchiveInfo[arcInfoIdx].mHeapId);
        }
        void *dst = new (heap, alignment) u8[dstSize];
        if (arcInfoIdx >= 0) {
            fn_801D3644();
        }

        sDecompThreadData.src = data;
        sDecompThreadData.dst = dst;
        sDecompThreadData.expandSize = expandSize;
        sDecompThreadData.dstSize = dstSize;
        sDecompThreadData.arcInfoIdx = arcInfoIdx;
        sDecompThreadData.deleteSrc = deleteSrc;

        OSCreateThread(
            &gFileManager->mThread,
            CFileManager::fn_801D47B8, &sDecompThreadData,
            &gFileManager->mThreadStack[THREAD_STACK_SIZE], THREAD_STACK_SIZE * sizeof(u32),
            31, 1
        );
        OSResumeThread(&gFileManager->mThread);

        return dst;
    }

    return NULL;
}

void *CFileManager::fn_801D47B8(void *arg) {
    DecompThreadData *data = (DecompThreadData *)arg;

    fn_801D47F8((u8 *)data->src, (u8 *)data->dst, data->expandSize, data->dstSize, data->arcInfoIdx, data->deleteSrc);
    return NULL;
}

// Yaz0 decompression.
bool CFileManager::fn_801D47F8(u8 *src, u8 *dst, u32 expandSize, u32 dstSize, s32 arcInfoIdx, BOOL deleteSrc) {
    DCInvalidateRange(dst, dstSize);

    s32 srcIdx = 0x10;
    u8 mask = 0;
    u8 opByte;

    for (s32 dstIdx = 0; dstIdx < expandSize; mask >>= 1) {
        if (mask == 0) {
            mask = 0b10000000;
            opByte = src[srcIdx++];
        }

        if (opByte & mask) {
            dst[dstIdx++] = src[srcIdx++];
        }
        else {
            s32 packed = src[srcIdx] << 8 | src[srcIdx + 1];
            srcIdx += 2;

            s32 runIdx = dstIdx - (packed & 0x0FFF);
            s32 runLen = ((packed >> 12) == 0) ?
                (src[srcIdx++] + 0xF + 3) :
                ((packed >> 12) + 2);

            for (; runLen > 0; runLen--, dstIdx++, runIdx++) {
                dst[dstIdx] = dst[runIdx - 1];
            }
        }
    }

    if (deleteSrc) {
        delete[] src;
    }

    DCFlushRange(dst, dstSize);

    if (arcInfoIdx >= 0) {
        gFileManager->mArchiveInfo[arcInfoIdx].mState = eArchiveInfoState_Decompressed;
    }

    return false;
}

void CFileManager::fn_801D49D4(void) {
    s32 driveStatus = DVDGetDriveStatus();
    switch (driveStatus) {
        case DVD_STATE_NO_DISK:
        case DVD_STATE_WRONG_DISK:
        case DVD_STATE_RETRY:
            if (unk34C) {
                unk34C();
            }
            CGameManager::fn_801D7538(driveStatus);
            if (unk350) {
                unk350();
            }
            break;
    }
}
