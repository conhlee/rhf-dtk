#ifndef GAME_PSEUDO3D_HPP
#define GAME_PSEUDO3D_HPP

#include <revolution/types.h>

class CPseudo3D {
private:
    f32 mCenterX, mCenterY;
    f32 mScale;
    f32 mFarX, mFarY, mFarZ;

public:
    virtual ~CPseudo3D(void);

    CPseudo3D(void);

    void fn_80072A14(f32 centerX, f32 centerY, f32 scale, f32 focX, f32 focY, f32 camZ);
    void fn_80072A54(f32 x, f32 y, f32 z, f32 *xOut, f32 *yOut, f32 *scaleOut);
};

#endif