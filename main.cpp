#include <iostream>
#include <string>

#include "8_task/file/FileSource.hpp"
#include "8_task/file/FileSourceBuffer.hpp"

#include "8_task/string/StringSource.hpp"
#include "8_task/string/StringSourceBuffer.hpp"



int main() {
    /* FILE */
    std::string in_file = "8_task/file/in.txt";
    FileSource fs = FileSource(in_file);

    fs.open();

    fs.write('T');
    fs.write('R');
    fs.write('P');
    fs.write('U');

    std::cout << fs.read_char() << std::endl;
    std::cout << fs.read_char() << std::endl;
    std::cout << fs.read_char() << std::endl;
    std::cout << fs.read_char() << std::endl;

    fs.write("rrrr ");
    std::cout << fs.read_string() << std::endl;

    fs.write(678);
    fs.write(" ");
    std::cout << fs.read_int() << std::endl;

    fs.write("tttt ");
    std::cout << fs.read_string() << std::endl;

    fs.close();


    // StringSource ss = StringSource();
    // ss.open();

    // ss.write('q');
    // ss.write('w');
    // ss.write('e');
    // ss.write(-89);   // check for neg too
    // ss.write(' ');
    // ss.write("rty ");

    // std::cout << ss.read_char() << std::endl;
    // std::cout << ss.read_char() << std::endl;
    // std::cout << ss.read_char() << std::endl;
    // std::cout << ss.read_int() << std::endl;
    // std::cout << ss.read_string() << std::endl;
    // std::cout << ss.eof() << std::endl;

    // ss.close();

    // FileSourceBuffer fsb = FileSourceBuffer(in_file, 5);
    // fsb.open();

    // fsb.write('m');
    // fsb.write('a');
    // fsb.write('m');
    // fsb.write('a');

    // fsb.write('d');
    // fsb.write('a');
    // fsb.write('d');

    // fsb.write('l');
    // fsb.write('l');
    // fsb.write('l');
    // fsb.write('l');

    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;

    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;

    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;
    // std::cout << fsb.read_char() << std::endl;

    // fsb.close();


    // StringSourceBuffer ssb = StringSourceBuffer(5);
    // ssb.open();
    // ssb.write('m');
    // std::cout << ssb.read_char() << std::endl;

    // ssb.close();


    return 0;
};