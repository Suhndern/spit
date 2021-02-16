#include <iostream>
#include <fstream>
#include <cstdint>
#include "spit.hpp"

// This example demonstrates how Spit is not restricted to operating on string literals,
// by reading a file into memory, display the contents of said file,
// and then spitting out the integer representation of the first 8 bytes of the file contents.
int main() {
    std::basic_string<char>lorem_filename ("lorem.txt");
    std::ifstream lorem_file (lorem_filename);

    // check if file is open
    if (lorem_file.is_open() != true) {
        std::cerr << "Could not open file \"" << lorem_filename << "\"" << std::endl;
        return 1;
    }

    // get pointer to file buffer
    std::filebuf* lorem_buf = lorem_file.rdbuf();

    // determine file size
    std::size_t lorem_filesize = lorem_buf->pubseekoff (0, lorem_file.end, lorem_file.in);
    lorem_buf->pubseekpos (0, lorem_file.in);

    // allocate memory to char buffer
    char* buffer = new char[lorem_filesize];

    // get file data
    lorem_buf ->sgetn (buffer, lorem_filesize);

    // close file
    lorem_file.close();

    std::cout << "In this example, file \"" << lorem_filename << "\" is read into memory." << std::endl;
    std::cout << "Spit can only convert and spit the integer representation of an 8-byte string, at most." << std::endl << std::endl;

    std::cout << "The contents of file \"" << lorem_filename << "\" are as follows:" << std::endl;
    std::cout << buffer << std::endl << std::endl;

    std::cout << "Again, Spit will only convert and spit the first 8 bytes, due to the nature of 64-bit variables." << std::endl;
    std::cout << "Observe:" << std::endl;
    std::cout << std::showbase << std::hex << spit::atoi(buffer) << std::endl;
    std::cout << "  ";
    for (int i = 7; i > -1; --i) { std::printf("%-2c", buffer[i]); }
    std::cout << std::endl;

    delete [] buffer;
}
