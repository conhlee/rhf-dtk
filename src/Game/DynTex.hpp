#ifndef GAME_DYNTEX_HPP
#define GAME_DYNTEX_HPP

#include <revolution/types.h>

#include <revolution/GX.h>

class CDynTex {
public:
    typedef void (*DrwUpdateFn)(void *texData);

public:
    CDynTex(DrwUpdateFn drwUpdateFn);
    ~CDynTex();

    void update(GXPixelFmt pixelFmt, GXZFmt zFmt);

    GXTexObj *getTexObj(void) { return &mTexObj; }

private:
    GXTexObj mTexObj;

    u32 mTexDataSize;
    void *mTexData;

    u16 mOriginX, mOriginY;
    u16 mWidth, mHeight;

    DrwUpdateFn mDrwUpdateFn;
};

#endif
