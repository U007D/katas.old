#ifndef USER_DEFINED_TYPES_H
#define USER_DEFINED_TYPES_H

#include <cstdint>

//Rust-style abbreviated types
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isz = ptrdiff_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usz = size_t;

using i8f = int_fast8_t;
using i16f = int_fast16_t;
using i32f = int_fast32_t;
using i64f = int_fast64_t;

using u8f = uint_fast8_t;
using u16f = uint_fast16_t;
using u32f = uint_fast32_t;
using u64f = uint_fast64_t;

using f32 = float;
using f64 = double;
using f80 = long double;

//Support for forcing user-defined literals to be evaluated at compile-time
template<unsigned long long sum, char... rest>
struct IntegerLiteralParser;

template<unsigned long long sum>
struct IntegerLiteralParser<sum>
{
    static const unsigned long long value = sum;
};

template<unsigned long long sum, char first, char... rest>
struct IntegerLiteralParser<sum, first, rest...>
{
    static_assert((first >= '0' && first <= '9'), "invalid input: expecting only numeric digits from 0-9");
    static const unsigned long long value = IntegerLiteralParser<sum * 10 + static_cast<unsigned long long>(first - '0'), rest...>::value;
};

//TODO: Add support for parsing floating point values

//Add common fixed-width signed value literals
template<char... chars> constexpr i8 operator ""_i8() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr i16 operator ""_i16() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr i32 operator ""_i32() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr i64 operator ""_i64() { return {IntegerLiteralParser<0, chars...>::value}; }

//Add common fixed-width unsigned value literals
template<char... chars> constexpr u8 operator ""_u8() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr u16 operator ""_u16() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr u32 operator ""_u32() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr u64 operator ""_u64() { return {IntegerLiteralParser<0, chars...>::value}; }

//Add literals for ptrdiff_t and size_t
template<char... chars> constexpr isz operator ""_isz() { return {IntegerLiteralParser<0, chars...>::value}; }
template<char... chars> constexpr usz operator ""_usz() { return {IntegerLiteralParser<0, chars...>::value}; }

//TODO: Add float & double support when FloatIntegerLiteralParser is implemented

#endif //USER_DEFINED_TYPES_H
