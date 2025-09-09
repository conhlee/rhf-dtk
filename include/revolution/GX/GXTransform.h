#ifndef RVL_SDK_GX_TRANSFORM_H
#define RVL_SDK_GX_TRANSFORM_H
#include <revolution/types.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/MTX.h>
#ifdef __cplusplus
extern "C" {
#endif

#define GX_PROJECTION_SZ 7
#define GX_VIEWPORT_SZ 6

void GXSetProjection(const Mtx44 proj, GXProjectionType type);

void GXLoadPosMtxImm(const Mtx mtx, u32 id);

void GXSetCurrentMtx(u32 id);

void GXSetViewportJitter(f32 ox, f32 oy, f32 sx, f32 sy, f32 near, f32 far,
                         u32 nextField);
void GXSetViewport(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz);
void GXGetViewportv(f32 view[GX_VIEWPORT_SZ]);

void GXGetScissor(u32* x, u32* y, u32* w, u32* h);

void GXSetClipMode(GXClipMode mode);

#ifdef __cplusplus
}
#endif
#endif