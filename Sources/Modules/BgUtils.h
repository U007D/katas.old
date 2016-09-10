//
// Created by bRad on 8/25/16.
//

#ifndef BG_UTILS_H
#define BG_UTILS_H

#include <cstdint>

//Add literals for size_t and ptrdiff_t
constexpr size_t operator ""_z(uintmax_t v) { return static_cast<size_t>(v); }
constexpr ptrdiff_t operator ""_t(uintmax_t v) { return static_cast<ptrdiff_t>(v); }

#endif //BG_UTILS_H
