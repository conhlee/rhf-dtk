#ifndef GAMEUTIL_CSCENE_HPP
#define GAMEUTIL_CSCENE_HPP

#include <revolution/types.h>

#include "Mem.hpp"

#define SCENE_DECL_CREATE_FN() static CScene *create(u16 heapId);
#define SCENE_IMPL_CREATE_FN(_className)     \
    CScene *_className::create(u16 heapId) { \
        fn_801D369C(heapId);                 \
        _className *scene = new _className;  \
        fn_801D3644();                       \
        scene->setHeapId(heapId);            \
        return scene;                        \
    }

class CScene {
public:
    typedef CScene *(*CreateFn)(u16 heapId);
    enum EState {
        eState_Unprepared = 0,
        eState_Preparing = 1,
        eState_Prepared = 2,
        eState_3 = 3,
        eState_4 = 4,
        eState_5 = 5,
        eState_Finished = 6
    };

    virtual void _08(void); // deinit
    virtual ~CScene(void) {}
    virtual void _10(void) = 0; // loadResources
    virtual void _14(void); // init
    virtual void _18(void); 
    virtual void _1C(void); // draw
    virtual void _20(void); // deloadResources
    virtual bool _24(void); // areResourcesReady
    virtual void _28(void); // update

    CScene(void) {
        mState = eState_Unprepared;
        unk04 = 1;
    }

    void fn_801D83BC(void);
    void fn_801D83DC(void);
    void fn_801D8554(void);
    void fn_801D8578(void);

    EState getState(void) const { return mState; }

    u16 getHeapId(void) const { return mHeapId; }
    void setHeapId(u16 heapId) { mHeapId = heapId; }

private:
    u8 unk04;
    EState mState;
    u16 mHeapId;
    u8 unk0E;
};

#endif