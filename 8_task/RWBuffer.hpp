#pragma once 
#include "ReaderWriter.hpp"
#include "SourceBuffer.hpp"
#include "IOException.hpp"

class ReaderWriterBuffer: public SourceBuffer, public ReaderWriter {
    public:
        ReaderWriterBuffer(int buffer_size): SourceBuffer(buffer_size) {}

        char read_char();
        int read_int();
        std::string read_string();
        void write(const char& ch);
        void write(const int& num);
        void write(const std::string& str);
};


