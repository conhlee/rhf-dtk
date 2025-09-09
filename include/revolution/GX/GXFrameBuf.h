#ifndef RVL_SDK_GX_FRAMEBUF_H
#define RVL_SDK_GX_FRAMEBUF_H
#include <revolution/GX/GXTypes.h>
#include <revolution/types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GXRenderModeObj {
    u32 tvInfo;               // at 0x0
    u16 fbWidth;              // at 0x4
    u16 efbHeight;            // at 0x6
    u16 xfbHeight;            // at 0x8
    u16 viXOrigin;            // at 0xA
    u16 viYOrigin;            // at 0xC
    u16 viWidth;              // at 0xE
    u16 viHeight;             // at 0x10
    u32 xfbMode;              // at 0x14
    u8 field_rendering;       // at 0x18
    u8 aa;                    // at 0x19
    u8 sample_pattern[12][2]; // at 0x1A
    u8 vfilter[7];            // at 0x32
} GXRenderModeObj;

extern GXRenderModeObj GXNtsc480IntDf;
extern GXRenderModeObj GXPal528IntDf;
extern GXRenderModeObj GXEurgb60Hz480IntDf;
extern GXRenderModeObj GXMpal480IntDf;

void GXAdjustForOverscan(const GXRenderModeObj* rmin, GXRenderModeObj* rmout, u16 hor, u16 ver);

void GXSetDispCopySrc(u16 left, u16 top, u16 wd, u16 ht);
void GXSetTexCopySrc(u16 x, u16 y, u16 w, u16 h);
void GXSetDispCopyDst(u16 wd, u16 hd);
void GXSetTexCopyDst(u16 w, u16 h, GXTexFmt fmt, GXBool mipmap);

void GXSetCopyClamp(GXCopyClamp clamp);

u32 GXSetDispCopyYScale(f32 vscale);

void GXSetCopyClear(GXColor color, u32 z);
void GXSetCopyFilter(GXBool, u8 sample_pattern[12][2], GXBool, u8 vfilter[7]);

void GXSetDispCopyGamma(GXGamma gamma);

void GXCopyDisp(void*, GXBool);
void GXCopyTex(void*, GXBool);

f32 GXGetYScaleFactor(u16 efbHeight, u16 xfbHeight);

void GXPixModeSync();

#ifdef __cplusplus
}
#endif
#endif