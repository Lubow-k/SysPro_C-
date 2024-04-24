#pragma once
#include <cmath>
#include "../ReaderWriter.hpp"
#include "../IOException.hpp"


class FileSource: public ReaderWriter {
    const char* file_name;
    bool file_open;

  protected:
    FILE* source;

  public:
    FileSource(std::string file_name): file_name(file_name.c_str()), file_open(false) {}     // maybe check for existing of file -> throw 
    FileSource(FileSource& otheer)=delete;
    FileSource(FileSource&& otheer)=delete;
    ~FileSource() { if (file_open) { fclose(source); } }


    bool is_open();
    bool eof();
    void close();
    void open();

    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str);    

};