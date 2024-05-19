#pragma once 
#include "FileSource.hpp"
#include "../ReaderWriter.hpp"


class FileRW: public FileSource, public ReaderWriter {
  public:
    FileRW(std::string file_name): FileSource(file_name) {}
    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str); 
};