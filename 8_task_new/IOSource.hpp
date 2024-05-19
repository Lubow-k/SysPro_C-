#pragma once

class IOSource {
  public:
    virtual bool is_open() = 0;
    virtual bool eof() = 0;
    virtual void close() = 0;
    virtual void open() = 0;
};