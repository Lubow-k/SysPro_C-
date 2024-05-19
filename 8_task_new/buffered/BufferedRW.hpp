#pragma once
#include "BufferedWriter.hpp"
#include "BufferedReader.hpp"

class BufferedRW: public BufferedReader, public BufferedWriter {
  public:
    BufferedRW(size_t buffer_size): BufferedWriter(buffer_size), BufferedReader(buffer_size) {}
};