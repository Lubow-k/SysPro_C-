#include "FileRWBuffer.hpp"



bool FileRWBuffer::append_to_resource() {
    int pos = get_write();
    fseek(source, writing_pos, 0);
    for (size_t i = 0; i < pos; i++) {
        fprintf(source, "%c", buffer_write[i]);
    }
    writing_pos += pos;
    zero_write();
    return pos > 0;
}

bool FileRWBuffer::get_from_resource() {
    fseek(source, reading_pos, 0);
    char ch;
    for (size_t i = 0; i < buffer_size; i++) {
        fscanf(source, "%c", &ch);
        if (eof() && i == 0) { 
            if (append_to_resource()) {
                return get_from_resource();
            }
            return false;
        }
        buffer_read[i] = ch;
        reading_pos++;
    }
    return true;
}
