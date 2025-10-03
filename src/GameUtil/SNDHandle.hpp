#ifndef GAMEUTIL_SNDHANDLE_HPP
#define GAMEUTIL_SNDHANDLE_HPP

#include <revolution/types.h>

#include <nw4r/snd.h>

// TODO: maybe move this into SoundManager, since that's where the dtor impl is?
class SNDHandle : public nw4r::snd::SoundHandle {
public:
    virtual ~SNDHandle(void);
};

#endif