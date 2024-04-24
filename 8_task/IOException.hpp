#pragma once
#include <stdexcept>
#include <string>

class IOException: public std::exception {
    const char* message;
  public:
    IOException(const char* m): message(m) {}
    const char* what () { return message; }
};

class FileException : public IOException{
  public:
    FileException(const char* m): IOException(m) {}
};

class StringException : public IOException{
  public:
    StringException(const char* m): IOException(m) {}
};