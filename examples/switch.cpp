#include <iostream>
#include "spit.hpp"

// This example demonstrates Spit's robustness, or lack thereof,
// regarding different Unicode encodings of string literals.
// Spit is a very naïve library, in that sense.
int main (int argc, char* argv[]) {
	if (argc < 2) return 1;
	
    std::cout << argv[1] << std::endl;
    std::cout << std::showbase << std::hex << spit::atoi(argv[1]) << std::endl;

    switch (spit::atoi (argv[1])) {

    // Spit was designed with ASCII in mind
    case spit::atoi("-hello"): {
        std::cout << "Hello!" << std::endl;
    } break;
    case spit::atoi("-bye"): {
        std::cout << "Bye!" << std::endl;
    } break;

    // Encoding a string literal in multi-byte code points is possible
    // Note, however, that Spit will only process the first 8 bytes of a string
    // Also note that if you go this route, you must perform proper translation
    // from whatever encoding the OS uses to whatever encoding YOU use.
    case spit::atoi("-résumé"): { // works on UTF-8 locales
        std::cout << "You're hired!" << std::endl;
    } break;

#if 0
    // Spit only truncates in terms of bytes, not code points
    // Therefore, the following <spit::atoi> call yields the same result as the previous call
    // Which ultimately results in a compiler error for a "duplicate case value"
    case spit::atoi("-résumè"): {
        std::cout << "You're fired!" << std::endl;
    } break;
#endif

    // Ditto.
    case spit::atoi("-bananas-are-great"): {
        std::cout << "Yeah!" << std::endl;
    } break;

#if 0
    case spit::atoi("-bananas-are-awful"): {
        std::cout << "Right on!" << std::endl;
    } break;
    // You can say whatever you want about bananas;
    // Spit will only see "-bananas" and immediately agree with you.
#endif
    }
}
