# Spit
Spit is a header-only C++17 library that provides the integer representation of a string up to 8 bytes in length.

## Code Example
Code examples are provided in the [examples/](examples/) directory.

## Motivation
Unlike other languages, the `switch`/`case` construct in C++ cannot be applied on string variables, only integers. This forces the programmer of a function that performs comparisons on strings to utilize a series of `if`/`else` statements, which precludes the advantages a `switch` can provide. This library exists to workaround this limitation.

## Build
If you wish to build the examples, then the following steps should suffice:
```
cd <project root>
mkdir build && cd build
cmake ..
make
```

## License
Licensing details can be found in [COPYING](COPYING).
