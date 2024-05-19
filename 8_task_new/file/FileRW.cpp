#include "FileRW.hpp"


/* Write */

void FileRW::write(const char& ch) {
  fseek(source, writing_pos++, 0);
  fprintf(source, "%c", ch);
}

void FileRW::write(const int& num) {
  fseek(source, writing_pos, 0);
  if (num == 0) {
    writing_pos++;
  } else {
    writing_pos += int(log10(num) + 1);
  }
  fprintf(source, "%d", num);
}

void FileRW::write(const std::string& str) {
  fseek(source, writing_pos, 0);
  writing_pos += str.size();
  fprintf(source, "%s", str.c_str());
}

/* Read */

char FileRW::read_char() {
  fseek(source, reading_pos++, 0);    
  char ch;
  if (fscanf(source, "%c", &ch) && ! eof()) { 
    return ch; 
  };
  throw FileException("Error while reading char");
}


int FileRW::read_int() {
  fseek(source, reading_pos, 0);    
  int num;
  if (fscanf(source, "%d", &num) && ! eof()) { 
    if (num == 0) { 
      reading_pos += 2; 
    } else {
      reading_pos += int(log10(num) + 1) + 1;
    }
    return num; 
  };
  throw FileException("Error while reading int");
}


std::string FileRW::read_string() {
  fseek(source, reading_pos, 0);    
  char str[MAX_LEN];
  if (fscanf(source, "%s", str) && ! eof()) { 
    std::string res = str;
    reading_pos += res.size() + 1;
    return res; 
  };
  throw FileException("Error while reading string");
}
