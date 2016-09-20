#ifndef BG_UTILS_H
#define BG_UTILS_H

#include <cstdint>

#include "AbbreviatedTypes.h"

//Add common fixed-width signed value literals
constexpr i8 operator ""_i8(uintmax_t v)
{
	return v < INT8_MIN || v > INT8_MAX ? throw std::overflow_error("int8_t overflow") : static_cast<i8>(v);
}

constexpr i16 operator ""_i16(uintmax_t v)
{
	return v < INT16_MIN || v > INT16_MAX ? throw std::overflow_error("int16_t overflow") : static_cast<i16>(v);
}

constexpr i32 operator ""_i32(uintmax_t v)
{
	return v < INT32_MIN || v > INT32_MAX ? throw std::overflow_error("int32_t overflow") : static_cast<i32>(v);
}

constexpr i64 operator ""_i64(uintmax_t v)
{
	return v < INT64_MIN || v > INT64_MAX ? throw std::overflow_error("int64_t overflow") : static_cast<i64>(v);
}

//Add common fixed-width unsigned value literals
constexpr u8 operator "" _u8(uintmax_t v)
{
	return v > UINT8_MAX ? throw std::overflow_error("uint8_t overflow") : static_cast<u8>(v);
}

constexpr u16 operator ""_u16(uintmax_t v)
{
	return v > UINT16_MAX ? throw std::overflow_error("uint16_t overflow") : static_cast<u16>(v);
}

constexpr u32 operator ""_u32(uintmax_t v)
{
	return v > UINT32_MAX ? throw std::overflow_error("uint32_t overflow") : static_cast<u32>(v);
}

constexpr u64 operator ""_u64(uintmax_t v)
{
	return v > UINT64_MAX ? throw std::overflow_error("uint64_t overflow") : static_cast<u64>(v);
}

//Add literals for ptrdiff_t and size_t
constexpr isz operator ""_isz(uintmax_t v)
{
	return v < PTRDIFF_MIN || v > PTRDIFF_MAX ? throw std::overflow_error("ptrdiff_t overflow") : static_cast<isz>(v);
}

constexpr usz operator ""_usz(uintmax_t v)
{
	return v > SIZE_MAX ? throw std::overflow_error("size_t overflow") : static_cast<usz>(v);
}

#endif //BG_UTILS_H
