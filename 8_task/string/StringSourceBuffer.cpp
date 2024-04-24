#include "StringSourceBuffer.hpp"



bool StringSourceBuffer::append_to_resource() {
    int pos = get_write();
    for (size_t i = 0; i < pos; i++) {
        source += buffer_write[i];
    }
    zero_write();
    return pos > 0;
}

bool StringSourceBuffer::get_from_resource() {
    // may be ret how many chars read
    for (size_t i = 0; i < buffer_size; i++) {
        if (it == source.end() && i == 0) {
            if (append_to_resource()) { return get_from_resource(); }
            return false;
        }
        buffer_read[i] = *it++;
    }
    return true;
}


/* Move up the hierarchy: functions that use only get or append */


char StringSourceBuffer::read_char() {
    return get();
}

int StringSourceBuffer::read_int() {
    std::string num;
    char ch = get();
    while (ch != ' ') { num += ch; } 
    if (is_number(num)) {
        return stoi(num);
    }
    throw FileException("Not convertable to int");
}


std::string StringSourceBuffer::read_string() {
    std::string str;
    char ch = get();
    while (ch != ' ') { str += ch; } 
    return str;
}


void StringSourceBuffer::write(const char& ch) { append(ch); }

void StringSourceBuffer::write(const int& num) {
    std::string str = std::to_string(num);
    for (const char& ch: str) { append(ch); }
}

void StringSourceBuffer::write(const std::string& str) {
    for (const char& ch: str) { append(ch); }
}
