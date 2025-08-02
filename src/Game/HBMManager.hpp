#ifndef GAME_HBMMANAGER_HPP
#define GAME_HBMMANAGER_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CHBMManager : public TSingleton<CHBMManager> {
public:
    virtual void _08(void);
    virtual ~CHBMManager(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(void);
    virtual void _1C(void);
    virtual void _20(void);

    CHBMManager(void);

    void setUnk412(bool value) {
        mUnk412 = value;
    }
    void setUnk416(bool value) {
        mUnk416 = value;
    }

private:
    u8 _pad04[0x412-4];
    bool mUnk412;
    u8 _pad413[0x3];
    bool mUnk416;
    u8 _pad417[0x28];
};

extern CHBMManager *gHBMManager;

#endif
