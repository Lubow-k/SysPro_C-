#pragma once
#include <cmath>
#include "../ReaderWriter.hpp"
#include "../IOException.hpp"

#define MAX_LEN 500

class FileSource: virtual public IOSource {
    const char* file_name;
    bool file_open;

  protected:
    FILE* source;

  public:
    FileSource(std::string file_name): file_name(file_name.c_str()), file_open(false) {}     // maybe check for existing of file -> throw 
    FileSource(FileSource& otheer)=delete;
    FileSource(FileSource&& otheer)=delete;
    ~FileSource() { if (file_open) { fclose(source); } }


  void open() {
    FILE* fptr = fopen(file_name, "r+");  // reading and writing
    if (fptr == NULL) {
      throw FileException("Not able to open the file");
    }
    source = fptr;   
    file_open = true;
  }

  bool is_open() { return file_open; }
  bool eof() { return feof(source); }

  void close() { 
    fclose(source); 
    file_open = false;
  }  
};