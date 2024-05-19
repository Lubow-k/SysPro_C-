#include <iostream>
#include <fstream>
#include <string>
#include "assert.h"

#include "../file/FileRW.hpp"
#include "../file/FileRWBuffered.hpp"

#include "../string/StringRW.hpp"
#include "../string/StringRWBuffered.hpp"


std::string TEST_FILE = "8_task_new/input.txt";


void test_1() {
    // file source - write/read a char

    std::string in_file = TEST_FILE;
    FileRW frw = FileRW(in_file);
    frw.open();

    char array[6] = { 'S', 'Y', 'S', 'P', 'R', 'O' };

    for (int i = 0; i < 6; ++i) {
        frw.write(array[i]);
    }
    for (int i = 0; i < 6; ++i) {
        assert(array[i] == frw.read_char());
    }

    frw.close();
    std::cout << "Done #1\n";
}


void test_2() {
    // file source - write/read a string

    std::string in_file = TEST_FILE;
    FileRW frw = FileRW(in_file);
    frw.open();

    std::string str = "qwerty";
    frw.write(str + " ");
    assert(frw.read_string() == str);

    frw.close();
    std::cout << "Done #2\n";

}

void test_3() {
    // file source - write/read int

    std::string in_file = TEST_FILE;
    FileRW frw = FileRW(in_file);
    frw.open();

    int array[7] = { 234, 3, 5, 0, 23, 12, 78 };

    for (int i = 0; i < 7; ++i) {
        frw.write(array[i]);
        frw.write(" ");
    }
    for (int i = 0; i < 7; ++i) {
        assert(array[i] == frw.read_int());
    }

    frw.close();
    std::cout << "Done #3\n";

}


void test_4() {
    // string source - write/read char

    StringRW srw = StringRW();
    srw.open();

    char array[6] = { 'S', 'Y', 'S', 'P', 'R', 'O' };

    for (int i = 0; i < 6; ++i) {
        srw.write(array[i]);
    }
    for (int i = 0; i < 6; ++i) {
        assert(array[i] == srw.read_char());
    }

    srw.close();
    std::cout << "Done #4\n";
}


void test_5() {
    // string source - write/read a string

    StringRW srw = StringRW();
    srw.open();

    std::string str = "qwerty";
    srw.write(str + " ");
    assert(srw.read_string() == str);

    srw.close();
    std::cout << "Done #5\n";
}

void test_6() {
    // string source - write/read int

    StringRW srw = StringRW();
    srw.open();

    int array[7] = { 234, 3, 5, 0, 23, 12, 78 };

    for (int i = 0; i < 7; ++i) {
        srw.write(array[i]);
        srw.write(" ");
    }
    for (int i = 0; i < 7; ++i) {
        assert(array[i] == srw.read_int());
    }

    srw.close();
    std::cout << "Done #6\n";
}


void test_7() {
    // file source with buffer - write/read a char

    std::string in_file = TEST_FILE;
    std::fstream in(in_file, std::ios::out);        // clean file
    FileRWBuffered frw = FileRWBuffered(in_file, 4);
    frw.open();

    char array[6] = { 'S', 'Y', 'S', 'P', 'R', 'O' };

    for (int i = 0; i < 6; ++i) {
        frw.write(array[i]);
    }

    for (int i = 0; i < 6; ++i) {
        assert(array[i] == frw.read_char());
    }

    frw.close();
    std::cout << "Done #7\n";
}


void test_8() {
    // file source with buffer - write/read a string

    std::string in_file = TEST_FILE;
    std::fstream in(in_file, std::ios::out);                 // clean file
    FileRWBuffered frw = FileRWBuffered(in_file);            // default buffer size
    frw.open();

    std::string str = "qwerty";
    frw.write(str + " ");
    assert(frw.read_string() == str);

    frw.close();
    std::cout << "Done #8\n";
}

void test_9() {
    // file source with buffer - write/read int

    std::string in_file = TEST_FILE;
    std::fstream in(in_file, std::ios::out);        // clean file
    FileRWBuffered frw = FileRWBuffered(in_file, 5);

    frw.open();

    int array[7] = { 234, 3, 5, 0, 23, 12, 78 };

    for (int i = 0; i < 7; ++i) {
        frw.write(array[i]);
        frw.write(" ");
    }
    for (int i = 0; i < 7; ++i) {
        assert(array[i] == frw.read_int());
    }

    frw.close();
    std::cout << "Done #9\n";
}

void test_10() {
    // string source with buffer - write/read a char

    StringRWBuffered srw = StringRWBuffered(4);
    srw.open();

    char array[6] = { 'S', 'Y', 'S', 'P', 'R', 'O' };

    for (int i = 0; i < 6; ++i) {
        srw.write(array[i]);
    }

    for (int i = 0; i < 6; ++i) {
        assert(array[i] == srw.read_char());
    }

    srw.close();
    std::cout << "Done #10\n";
}


void test_11() {
    // string source with buffer - write/read a string

    StringRWBuffered srw = StringRWBuffered();       // default buffer size
    srw.open();

    std::string str = "qwerty";
    srw.write(str + " ");
    assert(srw.read_string() == str);

    srw.close();
    std::cout << "Done #11\n";
}

void test_12() {
    // file source with buffer - write/read int

    StringRWBuffered srw = StringRWBuffered(15);

    srw.open();

    int array[7] = { 234, 3, 5, 0, 23, 12, 78 };

    for (int i = 0; i < 7; ++i) {
        srw.write(array[i]);
        srw.write(" ");
    }
    for (int i = 0; i < 7; ++i) {
        assert(array[i] == srw.read_int());
    }

    srw.close();
    std::cout << "Done #12\n";
}





int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    test_10();
    test_11();
    test_12();
    return 0;
}