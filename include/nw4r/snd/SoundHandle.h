#ifndef NW4R_SND_SOUND_HANDLE_H
#define NW4R_SND_SOUND_HANDLE_H

/*******************************************************************************
 * headers
 */

#include <revolution/types.h>

#include "nw4r/snd/BasicSound.h"

#include "nw4r/ut/inlines.h" // ut::NonCopyable

/*******************************************************************************
 * classes and functions
 */

namespace nw4r { namespace snd
{
	// [R89JEL]:/bin/RVL/Debug/mainD.elf:.debug::0x2894f
	class SoundHandle : private ut::NonCopyable
	{
	// methods
	public:
		// cdtors
		SoundHandle() : mSound() {}
		~SoundHandle() { DetachSound(); }

		// methods
		void detail_AttachSound(detail::BasicSound *sound);
		bool IsAttachedSound() const { return mSound != NULL; }
		detail::BasicSound *detail_GetAttachedSound() { return mSound; }
		void DetachSound();

		u32 GetId() const
		{
			if (IsAttachedSound())
				return mSound->GetId();

			return detail::BasicSound::INVALID_ID;
		}

		void Pause(bool flag, int fadeFrames) const
		{
			if (IsAttachedSound())
				mSound->Pause(flag, fadeFrames);
		}

		bool IsPause() const
		{
			return IsAttachedSound() && mSound->IsPause();
		}

		void Stop(int fadeFrames) const
		{
			if (IsAttachedSound())
				mSound->Stop(fadeFrames);
		}

		void SetVolume(f32 volume, int frames) const
		{
			if (IsAttachedSound())
				mSound->SetVolume(volume, frames);
		}

		void SetPitch(f32 pitch) const
		{
			if (IsAttachedSound())
				mSound->SetPitch(pitch);
		}

		void SetPan(f32 pan) const
		{
			if (IsAttachedSound())
				mSound->SetPan(pan);
		}

		void StartPrepared()
		{
			if (IsAttachedSound())
				mSound->StartPrepared();
		}

	// members
	private:
		/* base NonCopyable */			// size 0x00, offset 0x00
		detail::BasicSound	*mSound;	// size 0x04, offset 0x00
	}; // size 0x04
}} // namespace nw4r::snd

#endif // NW4R_SND_SOUND_HANDLE_H