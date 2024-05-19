#pragma once
#include "Buffered.hpp"

class BufferedWriter: public Buffered, public Writer {
  protected:
    virtual bool append_to_resource() = 0;    // implemented in real source

    void append(const char& ch) { 
      if (index == buffer_size) {             // full buffer
          append_to_resource();
          roll_back();
      }
      buffer[index++] = ch; 
    }

  public:
    BufferedWriter(size_t buffer_size_): Buffered(buffer_size_) {}
    void write(const char& ch) { append(ch); }

    void write(const int& num) {
      std::string str = std::to_string(num);
      for (const char& ch: str) { append(ch); }
    }

    void write(const std::string& str) { for (const char& ch: str) { append(ch); } }   
};