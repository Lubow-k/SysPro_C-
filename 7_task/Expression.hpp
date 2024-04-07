#pragma once
#include <string>

class Expression {
  public:
    virtual Expression* diff(std::string var) = 0; 
    virtual Expression* copy() = 0;
    virtual std::string print() = 0;
    virtual ~Expression() = default;
};