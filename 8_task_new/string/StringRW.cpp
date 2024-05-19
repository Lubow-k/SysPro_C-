#include "StringRW.hpp"
#include "../Utils.hpp"


/* Write */

void StringRW::write(const char& ch) {
    source += ch;
}

void StringRW::write(const int& num) {
  source += std::to_string(num);
}

void StringRW::write(const std::string& str) {
  source += str;
}

/* Read */

char StringRW::read_char() {
    if (it == source.end()) {
        throw StringException("EOF while reading char");
    }
    return *it++;
}


int StringRW::read_int() {
    std::string num;
    while (*it != ' ' && it != source.end()) { num += *it++; }
    if (it == source.end()) {
        throw StringException("EOF while reading int");
    }
    if (Utils::is_number(num)) {
        it++;
        return stoi(num);
    }
    throw StringException("Not convertable to int");
}


std::string StringRW::read_string() {
    std::string str;
    while (*it != ' ' && it != source.end()) { str += *it++; }
    if (it == source.end()) {
        throw StringException("EOF while reading string");
    }
    it++;
    return str;
}

