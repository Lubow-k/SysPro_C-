#include "StringSource.hpp"


/* Write */

void StringSource::write(const char& ch) {
    source += ch;
}

void StringSource::write(const int& num) {
  source += std::to_string(num);
}

void StringSource::write(const std::string& str) {
  source += str;
}

/* Read */

char StringSource::read_char() {
    if (it == source.end()) {
        throw StringException("EOF while reading char");
    }
    return *it++;
}


int StringSource::read_int() {
    std::string num;
    while (*it != ' ' && it != source.end()) { num += *it++; }
    if (it == source.end()) {
        throw StringException("EOF while reading int");
    }
    if (is_number(num)) {
        it++;
        return stoi(num);
    }
    throw StringException("Not convertable to int");
}


std::string StringSource::read_string() {
    std::string str;
    while (*it != ' ' && it != source.end()) { str += *it++; }
    if (it == source.end()) {
        throw StringException("EOF while reading string");
    }
    it++;
    return str;
}

