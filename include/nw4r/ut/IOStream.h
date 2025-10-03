#ifndef NW4R_UT_IO_STREAM_H
#define NW4R_UT_IO_STREAM_H

/*******************************************************************************
 * headers
 */

#include <types.h>

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
	class IOStream
	{
	// typedefs
	public:
		typedef void StreamCallback(s32 result, IOStream *stream, void *arg);

	// methods
	public:
		// cdtors
		IOStream() :
			mAvailable	(false),
			mCallback	(NULL),
			mArg		(NULL)
		{
		}
		/* virtual ~IOStream() {} */ // virtual function ordering

		// virtual function ordering
		// vtable IOStream
		virtual ut::detail::RuntimeTypeInfo const *GetRuntimeTypeInfo() const
		{
			return &typeInfo;
		}
		virtual ~IOStream() {}

		virtual void Close() = 0;
		virtual s32 Read(void *dst, u32 size) = 0;
		virtual bool ReadAsync(void *dst, u32 size, StreamCallback *cb,
		                       void *cbArg);
		virtual void Write(void const *src, u32 size);
		virtual bool WriteAsync(void const *src, u32 size, StreamCallback *cb,
		                        void *cbArg);
		virtual bool IsBusy() const;
		virtual bool CanAsync() const = 0;
		virtual bool CanRead() const = 0;
		virtual bool CanWrite() const = 0;
		virtual u32 GetOffsetAlign() const { return 1; }
		virtual u32 GetSizeAlign() const { return 1; }
		virtual u32 GetBufferAlign() const { return 1; }

		// methods
		bool IsAvailable() const { return mAvailable; }

	// static members
	public:
		static ut::detail::RuntimeTypeInfo const typeInfo;

	// members
	protected:
		/* vtable */					// size 0x04, offset 0x00
		bool			mAvailable;		// size 0x01, offset 0x04
		/* 3 bytes padding */
		s32				mAsyncResult;	// size 0x04, offset 0x08
		StreamCallback	*mCallback;		// size 0x04, offset 0x0c
		void			*mArg;			// size 0x04, offset 0x10
	}; // size 0x14
}} // namespace nw4r::ut

#endif // NW4R_UT_IO_STREAM_H
