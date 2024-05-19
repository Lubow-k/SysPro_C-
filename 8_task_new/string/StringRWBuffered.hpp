#pragma once
#include "../buffered/BufferedRW.hpp"
#include "StringSource.hpp"


class StringRWBuffered: public StringSource, public BufferedRW {
  public:
    StringRWBuffered(int buffer_size): BufferedRW(buffer_size) {}
    StringRWBuffered(): BufferedRW(50) {}

    bool append_to_resource() {
        int pos = BufferedWriter::index;
        for (size_t i = 0; i < pos; i++) {
            source += BufferedWriter::buffer[i];
        }
        BufferedWriter::roll_back();
        return pos > 0;
    }

    bool get_from_resource() {
        for (size_t i = 0; i < BufferedReader::buffer_size; i++) {
            if (it == source.end() && i == 0) {
                if (append_to_resource()) { return get_from_resource(); }
                return false;
            }
            BufferedReader::buffer[i] = *it++;
        }
        return true;
    }
    
};

