#ifndef GAMEUTIL_SNDHANDLE_HPP
#define GAMEUTIL_SNDHANDLE_HPP

#include <revolution/types.h>

#include <nw4r/snd.h>

class SNDHandle : public nw4r::snd::SoundHandle {
public:
    virtual ~SNDHandle();
};

#endif