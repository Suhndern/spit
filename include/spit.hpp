#ifndef SPIT_HPP
#define SPIT_HPP
#include <climits>
#include <string_view>

namespace spit {
    const int byte = CHAR_BIT;
    constexpr inline int min (int x, int y) {
        #include "spit-min.inl"
    }

    constexpr unsigned long long atoi (std::string_view const str) {
        #include "spit-atoi.inl"
    }

    constexpr unsigned long long atoi (std::u16string_view const str) {
        #include "spit-atoi.inl"
    }

    constexpr unsigned long long atoi (std::u32string_view const str) {
        #include "spit-atoi.inl"
    }
}
#endif
