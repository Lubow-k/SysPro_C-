#pragma once
#include <string>
#include <iostream>
#include "IOException.hpp"

class SourceBuffer {
    size_t index_write = 0;
    size_t index_read = 0;
    size_t copy_index = 0;

  protected:
    size_t buffer_size;
    char* buffer_write;
    char* buffer_read;
    virtual bool append_to_resource() = 0;
    virtual bool get_from_resource() = 0;

    void append(const char& ch) { 
      if (index_write == buffer_size) {      // full buffer
          append_to_resource();
      }
      buffer_write[index_write++] = ch; 
    }

    char get() { 
      if (index_read == 0 || index_read == buffer_size) {   // empty buffer
        bool status = get_from_resource();
        if (!status) { throw IOException("EOF while reading"); }
        index_read = 0;
      }
      return buffer_read[index_read++]; 
    }

    void zero_write() { index_write = 0; }
    size_t get_write() { return index_write; }

  public:
    SourceBuffer(size_t size): buffer_size(size) {
      buffer_write = new char[buffer_size];
      buffer_read = new char[buffer_size];
    }
    SourceBuffer(SourceBuffer& other)=delete;
    SourceBuffer(SourceBuffer&& other)=delete;
    ~SourceBuffer() {
      delete[] buffer_write;
      delete[] buffer_read;
    }
};