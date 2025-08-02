#include <revolution/GX.h>
#include <revolution/SC.h>

#include "Mem.hpp"

#include "LayoutManager.hpp"
#include "FileManager.hpp"

const char lbl_80329968[] = "\0";

CLayoutManager::CLayoutManager(void) {

}

CLayoutManager::~CLayoutManager(void) {
    _08();
}

void CLayoutManager::_10(void) {
    nw4r::lyt::LytInit();

    unk04 = new (eHeap_MEM2, 32) u8[0x100000];
    unk08 = MEMCreateExpHeap(unk04, 0x100000);
    MEMInitAllocatorForExpHeap(&unk0C, unk08, 4);
    nw4r::lyt::Layout::mspAllocator = &unk0C;
    unk1C = 0;
    unk38 = new nw4r::lyt::MultiArcResourceAccessor;
    unk4C = new nw4r::lyt::DrawInfo;
    if (SCGetAspectRatio() == SC_ASPECT_STD) {
        unk4C->SetLocationAdjust(false);
    }
    else { // SC_ASPECT_WIDE
        unk4C->SetLocationAdjust(true);
        unk4C->SetLocationAdjustScale(nw4r::math::VEC2((608.0f / 832.0f), 1.0f));
    }
    unk54 = NULL;
    mFontInfo = NULL;
}

void CLayoutManager::_08(void) {
    fn_801D705C();
    MEMDestroyExpHeap(unk08);
    delete unk38;
    delete[] unk04;
}

void CLayoutManager::_14(void) {
    unk50 = 0;
    unk51 = 0;
    unk58 = 1.0f;
    unk5C = 1.0f;
}

void CLayoutManager::_20(s32 arg1) {
    unk3C = new nw4r::lyt::ArcResourceLink[arg1];
    unk40 = arg1;
    unk41 = 0;
}

// TODO: ArcResourceLink::ArcResourceLink() is compiled with -O0

void CLayoutManager::_24(s32 arg1, const char *arg2) {
    unk3C[unk41].Set(gFileManager->fn_801D42CC(arg1), arg2);
    unk38->Attach(&unk3C[unk41]);
    unk41++;
}

void CLayoutManager::_28(void) {
    unk38->DetachAll();
    if (unk3C) {
        delete[] unk3C;
        unk3C = NULL;
    }
    unk40 = 0;
    unk41 = 0;
    if (unk1C) {
        unk1C = 0;
        MEMDestroyExpHeap(unk24);
        delete[] unk20;
        nw4r::lyt::Layout::mspAllocator = &unk0C;
    }
}

void CLayoutManager::fn_801D6AEC(u8 arg1) {
    unk51 = 0;
    unk50 = arg1;
    unk54 = new CLayout *[arg1];
}

void CLayoutManager::fn_801D6B2C(CLayout *arg1) {
    unk54[unk51] = arg1;
    unk54[unk51]->_0C();
    unk54[unk51]->_10();
    unk51++;
}

void CLayoutManager::fn_801D6BB0(void) {
    for (s32 i = 0; i < unk51; i++) {
        delete unk54[i];
    }
    if (unk54) {
        delete[] unk54;
        unk54 = NULL;
    }
    unk50 = 0;
    unk51 = 0;
}

CLayout *CLayoutManager::fn_801D6C50(u8 arg1) {
    return unk54[arg1];
}

void CLayoutManager::_18(void) {
    for (s32 i = 0; i < unk51; i++) {
        if (unk54[i]->getUnk10()) {
            unk54[i]->_18(unk4C);
        }
    }
}

void CLayoutManager::_1C(void) {
    fn_801D6D78();
    for (s32 i = 0; i < unk51; i++) {
        if (unk54[i]->getUnk11()) {
            unk54[i]->_1C(unk4C);
        }
    }
}

void CLayoutManager::fn_801D6D78(void) {
    GXSetCullMode(GX_CULL_NONE);
    GXSetZMode(FALSE, GX_NEVER, FALSE);
}

void CLayoutManager::fn_801D6DAC(u8 arg1) {
    unk49 = 0;
    unk48 = arg1;
    mFontInfo = new CFontInfo *[arg1];
    for (s32 i = 0; i < unk48; i++) {
        mFontInfo[i] = new CFontInfo;
    }
}

bool CLayoutManager::fn_801D6E2C(void *arg1, const char *arg2) {
    if (strstr(arg2, ".brfnt")) {
        mFontInfo[unk49]->fontType = eFontType_ResFont;
    }
    else if (strstr(arg2, ".brfna")) {
        mFontInfo[unk49]->fontType = eFontType_ArchiveFont;
    }

    switch (mFontInfo[unk49]->fontType) {
    case eFontType_ResFont:
        mFontInfo[unk49]->font = new nw4r::ut::ResFont;
        mFontInfo[unk49]->getResFont()->SetResource(arg1);
        break;
    case eFontType_ArchiveFont:
        u32 bufferSize = nw4r::ut::ArchiveFont::GetRequireBufferSize(arg1, lbl_80329968);
        mFontInfo[unk49]->buffer = new (eHeap_MEM2, 32) u8[bufferSize];
        mFontInfo[unk49]->font = new nw4r::ut::ArchiveFont;
        mFontInfo[unk49]->getArchiveFont()->Construct(mFontInfo[unk49]->buffer, bufferSize, arg1, lbl_80329968);
        break;
    }

    bool isArchiveFont = mFontInfo[unk49]->fontType == eFontType_ArchiveFont;

    mFontInfo[unk49]->unk04 = new nw4r::lyt::FontRefLink;
    mFontInfo[unk49]->unk04->Set(arg2, mFontInfo[unk49]->font);
    unk38->RegistFont(mFontInfo[unk49]->unk04);
    unk49++;

    return isArchiveFont;
}

void CLayoutManager::fn_801D705C(void) {
    for (s32 i = 0; i < unk49; i++) {
        unk38->UnregistFont(mFontInfo[i]->unk04);
        switch (mFontInfo[i]->fontType) {
        case eFontType_ResFont:
            mFontInfo[i]->getResFont()->RemoveResource();
            break;
        case eFontType_ArchiveFont:
            mFontInfo[i]->getArchiveFont()->Destroy();
            break;
        }
        delete mFontInfo[i]->unk04;
        delete mFontInfo[i]->font;
        delete[] mFontInfo[i]->buffer;
        delete mFontInfo[i];
    }
    if (mFontInfo) {
        delete[] mFontInfo;
        mFontInfo = NULL;
    }
    unk48 = 0;
    unk49 = 0;
}

void CLayoutManager::fn_801D717C(f32 arg1, f32 arg2) {
    unk58 = arg1;
    unk5C = arg2;
}

f32 CLayoutManager::fn_801D7188(void) {
    return unk58;
}

f32 CLayoutManager::fn_801D7190(void) {
    return unk5C;
}

void CLayoutManager::fn_801D7198(s32 arg1) {
    unk1C = 1;
    unk20 = new (eHeap_MEM2, 32) u8[arg1];
    unk24 = MEMCreateExpHeap(unk20, arg1);
    MEMInitAllocatorForExpHeap(&unk28, unk24, 4);
    nw4r::lyt::Layout::mspAllocator = &unk28;
}
