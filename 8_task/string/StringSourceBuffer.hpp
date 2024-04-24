#pragma once
#include <cmath>
#include "StringSource.hpp"
#include "../SourceBuffer.hpp"
#include "../IOException.hpp"


class StringSourceBuffer: public StringSource, public SourceBuffer {
    bool append_to_resource();
    bool get_from_resource();

  public:
    StringSourceBuffer(int buffer_size): SourceBuffer(buffer_size) {}    
    StringSourceBuffer(): StringSourceBuffer(100) {}
    ~StringSourceBuffer()=default;

    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str); 

};