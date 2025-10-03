#ifndef GAME_MYTAGPROCESSOR_HPP
#define GAME_MYTAGPROCESSOR_HPP

#include <revolution/types.h>

#include <nw4r/ut.h>

class CMyTagProcessor : public nw4r::ut::WideTagProcessor {
public:
    virtual ~CMyTagProcessor(void);

    virtual Operation Process(u16 ch, ContextType *pCtx);
    virtual Operation CalcRect(nw4r::ut::Rect *pRect, u16 ch,
                               ContextType *pCtx);

    CMyTagProcessor(void);

private:
    f32 mRubyScale;
    nw4r::ut::Color mTextColorStart;
    nw4r::ut::Color mTextColorEnd;
    nw4r::ut::Color mColorMappingMin;
    nw4r::ut::Color mColorMappingMax;
};

#endif
