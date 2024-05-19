#pragma once
#include "../IOException.hpp"
#include "../IOSource.hpp"


class StringSource: public IOSource {
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
};