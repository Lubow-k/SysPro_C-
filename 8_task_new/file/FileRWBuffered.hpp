#pragma once
#include "../buffered/BufferedRW.hpp"
#include "FileSource.hpp"


class FileRWBuffered: public FileSource, public BufferedRW {
  public:
    FileRWBuffered(std::string file_name, int buffer_size): FileSource(file_name), BufferedRW(buffer_size) {}
    FileRWBuffered(std::string file_name):  FileRWBuffered(file_name, 50) {}
    size_t reading_pos = 0;
    size_t writing_pos = 0;

    bool append_to_resource() {
        int pos = BufferedWriter::index;
        fseek(source, writing_pos, 0);
        for (size_t i = 0; i < pos; i++) {
            fprintf(source, "%c", BufferedWriter::buffer[i]);
        }
        writing_pos += pos;
        BufferedWriter::roll_back();
        return pos > 0;
    }

    bool get_from_resource() {
        fseek(source, reading_pos, 0);
        char ch;
        for (size_t i = 0; i < BufferedReader::buffer_size; i++) {
            fscanf(source, "%c", &ch);
            if (eof() && i == 0) { 
                if (append_to_resource()) {
                    return get_from_resource();
                }
                return false;
            }
            BufferedReader::buffer[i] = ch;
            reading_pos++;
        }
        return true;
    }


    
};

