#pragma once 
#include "StringSource.hpp"
#include "../ReaderWriter.hpp"


class StringRW: public StringSource, public ReaderWriter {
  public:
    StringRW()=default;
    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str); 
};