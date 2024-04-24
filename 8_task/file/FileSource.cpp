#include "FileSource.hpp"

#define MAX_LEN 500


void FileSource::open() {
  FILE* fptr = fopen(file_name, "r+");  // reading and writing
  if (fptr == NULL) {
    throw FileException("Not able to open the file.");
  }
  source = fptr;   
  file_open = true;
}

bool FileSource::is_open() { return file_open; }
bool FileSource::eof() { return feof(source); }

void FileSource::close() { 
  fclose(source); 
  file_open = false;
}

/* Write */

void FileSource::write(const char& ch) {
  fseek(source, writing_pos++, 0);
  fprintf(source, "%c", ch);
}

void FileSource::write(const int& num) {
  fseek(source, writing_pos, 0);
  writing_pos += int(log10(num) + 1);
  fprintf(source, "%d", num);
}

void FileSource::write(const std::string& str) {
  fseek(source, writing_pos, 0);
  writing_pos += str.size();
  fprintf(source, "%s", str.c_str());
}

/* Read */

char FileSource::read_char() {
  fseek(source, reading_pos++, 0);    
  char ch;
  if (fscanf(source, "%c", &ch) && ! eof()) { 
    return ch; 
  };
  throw FileException("Error while reading char");
}


int FileSource::read_int() {
  fseek(source, reading_pos, 0);    
  int num;
  if (fscanf(source, "%d", &num) && ! eof()) { 
    reading_pos += int(log10(num) + 1) + 1;
    return num; 
  };
  throw FileException("Error while reading int");
}


std::string FileSource::read_string() {
  fseek(source, reading_pos, 0);    
  char str[MAX_LEN];
  if (fscanf(source, "%s", str) && ! eof()) { 
    std::string res = str;
    reading_pos += res.size() + 1;
    return res; 
  };
  throw FileException("Error while reading string");
}

