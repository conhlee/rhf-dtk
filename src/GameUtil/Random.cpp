#include "Random.hpp"

CRandom sRandom;

CRandom::CRandom(u32 seed) {
    mX = seed;
    mSeed = seed;
}
CRandom::~CRandom(void) {}

u32 CRandom::nextU32(void) {
    mX = 7567025607324980273 * mX + 5279421;
    return mX >> 0x20;
}

u32 CRandom::nextU32(u32 range) {
    mX = 7567025607324980273 * mX + 5279421;
    return ((mX >> 0x20) * range) >> 0x20;
}

const f32 CRandom::mul = 2.3283064e-10f; // 1 / (2 ^ 32)

f32 CRandom::nextF32(void) {
    return mul * nextU32();
}

f32 CRandom::nextF32(f32 range) {
    return range * nextF32();
}
