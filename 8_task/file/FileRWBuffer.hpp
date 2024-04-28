#pragma once
#include <cmath>
#include "FileSource.hpp"
#include "../RWBuffer.hpp"
#include "../IOException.hpp"


class FileRWBuffer: public FileSource, public ReaderWriterBuffer {
    bool append_to_resource();
    bool get_from_resource();

  public:
    FileRWBuffer(std::string file_name, int buffer_size): FileSource(file_name), ReaderWriterBuffer(buffer_size) {}    
    FileRWBuffer(std::string file_name): FileRWBuffer(file_name, 100) {}  
    ~FileRWBuffer() { append_to_resource(); }

};

