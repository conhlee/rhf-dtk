#ifndef NW4R_UT_FILE_STREAM_H
#define NW4R_UT_FILE_STREAM_H

/*******************************************************************************
 * headers
 */

#include <types.h>

#include <nw4r/ut/IOStream.h>

/*******************************************************************************
 * types
 */

// forward declarations
namespace nw4r { namespace ut { namespace detail { class RuntimeTypeInfo; }}}

/*******************************************************************************
 * classes and functions
 */

namespace nw4r { namespace ut
{
	class FileStream : public IOStream
	{
	// enums
	public:
		enum SeekOrigin
		{
			SEEK_ORIGIN_SET,
			SEEK_ORIGIN_CUR,
			SEEK_ORIGIN_END
		};

	// nested types
	protected:
		class FilePosition
		{
		// methods
		public:
			// cdtors
			FilePosition() :
				mFileSize	(0),
				mPosition	(0)
			{
			}

			// gethods
			u32 GetFileSize() const { return mFileSize; }

			// sethods
			void SetFileSize(u32 size) { mFileSize = size; }

			// methods
			u32 Tell() const { return mPosition; }
			u32 Skip(long offset);
			u32 Append(long offset);
			void Seek(long offset, int origin);

		private:
			u32	mFileSize;	// size 0x04, offset 0x00
			u32	mPosition;	// size 0x04, offset 0x04
		}; // size 0x08

	// methods
	public:
		// cdtors
		FileStream() {}
		virtual ~FileStream() {}

		// virtual function ordering
		// vtable IOStream
		virtual ut::detail::RuntimeTypeInfo const *GetRuntimeTypeInfo() const
		{
			return &typeInfo;
		}

		// vtable FileStream
		virtual u32 GetSize() const = 0;
		virtual void Seek(s32 offset, u32 origin);
		virtual void Cancel();
		virtual bool CancelAsync(StreamCallback *cb, void *cbArg);
		virtual bool CanSeek() const = 0;
		virtual bool CanCancel() const = 0;
		virtual u32 Tell() const = 0;

	// static members
	public:
		static ut::detail::RuntimeTypeInfo const typeInfo;

	// members
	protected:
		/* base IOStream */	// size 0x14, offset 0x00
	}; // size 0x14
}} // namespace nw4r::ut

#endif // NW4R_UT_FILE_STREAM_H
