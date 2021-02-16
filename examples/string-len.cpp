#include <cstdio>
#include "spit.hpp"

int main () {
    // This example merely shows the resulting hexadecimal layout
    // of the same spat string literal encoded in UTF-8, UTF-16, and UTF-32
    std::printf(" 8-bit string \"Hello!\"\t -> \t 0x%016llx\n", spit::atoi( "Hello!"));
    std::printf("16-bit string \"Hello!\"\t -> \t 0x%016llx\n", spit::atoi(u"Hello!"));
    std::printf("32-bit string \"Hello!\"\t -> \t 0x%016llx\n", spit::atoi(U"Hello!"));

    return 0;
}
