#ifndef GAME_BALLOONLAYOUT_HPP
#define GAME_BALLOONLAYOUT_HPP

#include <revolution/types.h>

#include "Layout.hpp"

#include "MyTagProcessor.hpp"

#include <revolution/SC.h>

class CBalloonLayout : public CLayout {
public:
    virtual ~CBalloonLayout(void);
    virtual void _10(void);
    virtual void _14(void);

    CBalloonLayout(void) {
        setAnimationCount(0);
    }

    void fn_800399E4(void);
    void fn_80039D58(void);
    void fn_80039E00(u8 accessIdx, BOOL);
    void fn_80039E2C(u8 visible);
    void fn_80039E5C(u8 visible);
    void fn_80039E78(u8 visible);
    void fn_80039E94(f32 x, f32 y);
    void fn_80039F30(f32 x, f32 y, BOOL flipTail);
    void fn_80039FB0(f32 x, f32 y, BOOL flipTail);
    void fn_8003A030(f32 x, f32 y);
    void fn_8003A074(s16 bgColor[4], s16 fgColor[4]);
    void fn_8003A11C(void);
    void fn_8003A1D0(
        u8 accessIdx,
        f32 pX, f32 pY, f32 sX, f32 sY,
        bool hasTail, f32 tailX, f32 tailY, bool flipTailH
    );
    void fn_8003A418(u8 accessIdx, f32 y, f32 h);

private:
    f32 getScaledX(f32 x) {
        if (SCGetAspectRatio() == SC_ASPECT_WIDE) {
            x *= (608.0f / 832.0f);
        }
        return x;
    }

private:
    nw4r::lyt::Pane *mBoxParent;
    nw4r::lyt::Pane *mBoxTriangleStraight;
    nw4r::lyt::Pane *mBoxTriangleCurve;
    nw4r::lyt::Pane *mBoxWindow;
    nw4r::lyt::TextBox *mBoxTextbox;
    CMyTagProcessor *mBoxTextTagProcessor;
    s32 mBoxPaneAccessIdx;

    nw4r::lyt::Pane *mOverlayParent;
    nw4r::lyt::Pane *mOverlayPane;
    nw4r::lyt::TextBox *mOverlayTextbox;
    CMyTagProcessor *mOverlayTextTagProcessor;
    s32 mOverlayPaneAccessIdx;
};

#endif
