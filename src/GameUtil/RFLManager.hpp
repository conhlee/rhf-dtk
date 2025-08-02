#ifndef GAME_RFLMANAGER_HPP
#define GAME_RFLMANAGER_HPP

#include <revolution/types.h>

#include "Singleton.hpp"

class CRFLManager : public TSingleton<CRFLManager> {
public:
    virtual void _08(void);
    virtual ~CRFLManager(void);
    virtual void _10(void);

    CRFLManager(void);

    void fn_800C2C40(void);
    void fn_800C2C98(void);
    void fn_800C2CA4(void);
    void fn_800C2E04(void);

private:
};

extern CRFLManager *gRFLManager;

#endif
