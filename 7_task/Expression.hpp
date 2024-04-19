#pragma once
#include <string>

class Expression {
  public:
    Expression()=default;
    Expression(const Expression& other)=delete; 
    Expression(const Expression&& other)=delete; 
    Expression& operator=(Expression& other)=delete;
    Expression& operator=(Expression&& other)=delete;

    virtual Expression* diff(std::string var) = 0; 
    virtual Expression* copy() = 0;
    virtual explicit operator std::string() const = 0;
    virtual ~Expression() = default;
};