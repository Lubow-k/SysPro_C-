#pragma once
#include <cmath>
#include "StringSource.hpp"
#include "../RWBuffer.hpp"
#include "../IOException.hpp"


class StringRWBuffer: public StringSource, public ReaderWriterBuffer {
    bool append_to_resource();
    bool get_from_resource();

  public:
    StringRWBuffer(int buffer_size): ReaderWriterBuffer(buffer_size) {}    
    StringRWBuffer(): StringRWBuffer(100) {}
    ~StringRWBuffer()=default;
};