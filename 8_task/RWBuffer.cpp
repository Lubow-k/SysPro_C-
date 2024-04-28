#include "RWBuffer.hpp"


char ReaderWriterBuffer::read_char() {
    return get();
}


int ReaderWriterBuffer::read_int() {
    std::string num;
    char ch = get();
    while (ch != ' ') { num += ch; } 
    if (is_number(num)) {
        return stoi(num);
    }
    throw FileException("Not convertable to int");
}


std::string ReaderWriterBuffer::read_string() {
    std::string str;
    char ch = get();
    while (ch != ' ') { str += ch; } 
    return str;
}


void ReaderWriterBuffer::write(const char& ch) { append(ch); }

void ReaderWriterBuffer::write(const int& num) {
    std::string str = std::to_string(num);
    for (const char& ch: str) { append(ch); }
}

void ReaderWriterBuffer::write(const std::string& str) {
    for (const char& ch: str) { append(ch); }
}