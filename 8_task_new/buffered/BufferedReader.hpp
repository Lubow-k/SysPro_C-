#pragma once
#include "Buffered.hpp"
#include "../Utils.hpp"

class BufferedReader: public Buffered, public Reader {
  protected:
    virtual bool get_from_resource() = 0;         // implemented in real source

    char get() { 
      if (index == 0 || index == buffer_size) {   // empty buffer
        bool status = get_from_resource();
        if (!status) { throw IOException("EOF while reading"); }
        roll_back();
      }
      return buffer[index++]; 
    }

  public:
    BufferedReader(size_t buffer_size_): Buffered(buffer_size_) {}
    char read_char() { return get(); }

    int read_int() {
        std::string num;
        char ch = get();
        while (ch != ' ') { num += ch; ch = get(); } 
        if (Utils::is_number(num)) {
            return stoi(num);
        }
        throw FileException("Not convertable to int");
    }
    
    std::string read_string() {
        std::string str;
        char ch = get();
        while (ch != ' ') { 
            str += ch; 
            ch = get();
        } 
        return str;
    }   
};