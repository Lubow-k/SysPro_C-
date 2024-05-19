#pragma once
#include "../IOException.hpp"

class Buffered {
  protected:
    size_t index = 0;
    size_t buffer_size;
    char* buffer;

    void roll_back() { index = 0; }

  public:
    Buffered(size_t buffer_size_): buffer_size(buffer_size_) {
      buffer = new char[buffer_size];
    }
    Buffered(Buffered& other)=delete;
    Buffered(Buffered&& other)=delete;
    ~Buffered() { delete[] buffer; }
};