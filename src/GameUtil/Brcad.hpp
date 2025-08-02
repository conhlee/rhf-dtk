#ifndef GAMEUTIL_BRCAD_HPP
#define GAMEUTIL_BRCAD_HPP

#include <revolution/types.h>

struct CellAnimSpritePart {
    u16 regionX, regionY;
    u16 regionW, regionH;
    u16 texNumber;
    s16 posX, posY;
    f32 scaleX, scaleY;
    f32 angle;
    bool flipX, flipY;
    u8 opacity;
};

struct CellAnimSprite {
    u16 partCount;
    CellAnimSpritePart* parts;
};

struct CellAnimAnimationKey {
    u16 spriteIndex;
    u16 frameCount;
    s16 posX, posY;
    f32 scaleX, scaleY;
    f32 angle;
    u8 opacity;
};

struct CellAnimAnimation {
    u16 keyCount;
    CellAnimAnimationKey* keys;
};

#endif
