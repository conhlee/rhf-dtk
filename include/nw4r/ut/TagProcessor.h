#ifndef NW4R_UT_TAG_PROCESSOR_H
#define NW4R_UT_TAG_PROCESSOR_H
#include <nw4r/types_nw4r.h>

#include <nw4r/ut/TagProcessorBase.h>

namespace nw4r {
namespace ut {

typedef TagProcessorBase<char> TagProcessor;

typedef TagProcessorBase<wchar_t> WideTagProcessor;

} // namespace ut
} // namespace nw4r

#endif