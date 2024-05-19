#pragma once
#include <string>


class Reader {
  public:
    virtual char read_char() = 0;
    virtual int read_int() = 0;                            // until space
    virtual std::string read_string() = 0;                 // until space 
};


class Writer {
  public:
    virtual void write(const char& ch) = 0;
    virtual void write(const int& num) = 0;
    virtual void write(const std::string& str) = 0;      
};


class ReaderWriter: public Reader, public Writer {
  protected:
    size_t reading_pos = 0;
    size_t writing_pos = 0;
};