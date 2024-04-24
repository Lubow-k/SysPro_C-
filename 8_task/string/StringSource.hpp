#pragma once
#include "../ReaderWriter.hpp"
#include "../IOException.hpp"


class StringSource: public ReaderWriter {
    bool string_open;
  
  protected:
    std::string source;
    std::string::iterator it = source.begin();

  public:
    StringSource(): string_open(false) {}  
    StringSource(StringSource& otheer)=delete;
    StringSource(StringSource&& otheer)=delete;
    ~StringSource()=default;

    bool is_open() { return string_open; }
    bool eof() { return it == source.end(); }          
    void close() { string_open = false; }
    void open() { string_open = true; }

    char read_char();
    int read_int();
    std::string read_string(); 

    void write(const char& ch);
    void write(const int& num);
    void write(const std::string& str);    

};