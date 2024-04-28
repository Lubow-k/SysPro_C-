#pragma once
#include "IOSource.hpp"
#include <string>


class Reader: virtual public IOSource {
  public:
    virtual char read_char() = 0;
    virtual int read_int() = 0;                            // until space
    virtual std::string read_string() = 0;                 // until space 
};


class Writer: virtual public IOSource {
  public:
    virtual void write(const char& ch) = 0;
    virtual void write(const int& num) = 0;
    virtual void write(const std::string& str) = 0;      
};


class ReaderWriter: public Reader, public Writer {
  protected:
    static bool is_number(const std::string& str) {
      if (str.empty()) return false;
      auto iter { str.begin() };
      if (str.front() == '-') {
        if (str.size() > 1) ++iter; // neg number
        else return false;          // only -
      }
      return all_of(iter, str.end(), ::isdigit);
    }
    size_t reading_pos = 0;
    size_t writing_pos = 0;
};