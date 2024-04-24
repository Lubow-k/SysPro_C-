#pragma once
#include <cmath>
#include "FileSource.hpp"
#include "../SourceBuffer.hpp"
#include "../IOException.hpp"


class FileSourceBuffer: public FileSource, public SourceBuffer {
    bool append_to_resource();
    bool get_from_resource();

  public:
    FileSourceBuffer(std::string file_name, int buffer_size): FileSource(file_name), SourceBuffer(buffer_size) {}    
    FileSourceBuffer(std::string file_name): FileSourceBuffer(file_name, 100) {}  
    ~FileSourceBuffer() { append_to_resource(); }

    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str); 

};