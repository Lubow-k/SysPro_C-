#include "FileSourceBuffer.hpp"



bool FileSourceBuffer::append_to_resource() {
    int pos = get_write();
    fseek(source, writing_pos, 0);
    for (size_t i = 0; i < pos; i++) {
        fprintf(source, "%c", buffer_write[i]);
    }
    writing_pos += pos;
    zero_write();
    return pos > 0;
}

bool FileSourceBuffer::get_from_resource() {
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



char FileSourceBuffer::read_char() {
    return get();
}


int FileSourceBuffer::read_int() {
    std::string num;
    char ch = get();
    while (ch != ' ') { num += ch; } 
    if (is_number(num)) {
        return stoi(num);
    }
    throw FileException("Not convertable to int");
}


std::string FileSourceBuffer::read_string() {
    std::string str;
    char ch = get();
    while (ch != ' ') { str += ch; } 
    return str;
}


void FileSourceBuffer::write(const char& ch) { append(ch); }

void FileSourceBuffer::write(const int& num) {
    std::string str = std::to_string(num);
    for (const char& ch: str) { append(ch); }
}

void FileSourceBuffer::write(const std::string& str) {
    for (const char& ch: str) { append(ch); }
}
