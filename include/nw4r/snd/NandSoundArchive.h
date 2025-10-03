#ifndef NW4R_SND_NAND_SOUND_ARCHIVE_H
#define NW4R_SND_NAND_SOUND_ARCHIVE_H

#include <types.h>

#include "nw4r/snd/SoundArchive.h"
#include "nw4r/snd/SoundArchiveFile.h"

#include "nw4r/ut.h"

#include <revolution/NAND.h>

namespace nw4r {
namespace snd {

class NandSoundArchive : public SoundArchive {
private:
    struct NandFileStream;

public:
    NandSoundArchive();
    virtual ~NandSoundArchive(); // at 0x8

    void Close();

private:
    detail::SoundArchiveFileReader mFileReader; // at 0x108
    NANDFileInfo mFileInfo;                     // at 0x14C
    bool mOpen;                                 // at 0x1D8
};

} // namespace snd
} // namespace nw4r

#endif
