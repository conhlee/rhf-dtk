#ifndef GAMEUTIL_CRANDOM_HPP
#define GAMEUTIL_CRANDOM_HPP

#include <revolution/types.h>
#include <revolution/OS.h>

class CRandom {
public:
    virtual ~CRandom(void);

    CRandom(void) {
        mX = 0;
        mSeed = 0;
        reseed();
    }
    CRandom(u32 seed);

    void reseed(void) {
        u32 seed = OSGetTick();

        mX = seed;
        mSeed = seed;
    }

    u32 nextU32(void);
    u32 nextU32(u32 range);

    f32 nextF32(void);
    f32 nextF32(f32 range);

private:
    static const f32 mul;

    u64 mX;
    u64 mSeed;
};

extern CRandom sRandom;

#endif