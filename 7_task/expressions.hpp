#pragma once
#include "expression.hpp"


class Unary: public Expression {
  protected:
    Expression* op;
    Unary(Expression* op): op(op) {}
    ~Unary() { delete op; }
};

class Binary: public Expression {
  protected:
    Expression* op_1;
    Expression* op_2;
    virtual std::string get_sign() const = 0;
    Binary(Expression* op_1, Expression* op_2): op_1(op_1), op_2(op_2) {}
    explicit operator std::string() const {
      std::string str_1 = static_cast<std::string>(*op_1);
      std::string str_2 = static_cast<std::string>(*op_2);
      return "(" + str_1 + get_sign() + str_2 + ")"; 
    }
    ~Binary() {
      delete op_1;
      delete op_2;
    }
};


class Add: public Binary {
  public:
    Add(Expression* op_1, Expression* op_2): Binary(op_1, op_2) {} 
    std::string get_sign() const { return " + "; }
    Expression* diff(std::string var) { 
      return new Add(op_1->diff(var), op_2->diff(var)); 
    }
    Expression* copy() { 
      return new Add(op_1->copy(), op_2->copy());  
    }
};

class Sub: public Binary {
  public:
    Sub(Expression* op_1, Expression* op_2): Binary(op_1, op_2) {} 
    std::string get_sign() const { return " - "; }
    Expression* diff(std::string var) { 
      return new Sub(op_1->diff(var), op_2->diff(var)); 
    }
    Expression* copy() { 
      return new Sub(op_1->copy(), op_2->copy());  
    }
};

class Mult: public Binary {
  public:
    Mult(Expression* op_1, Expression* op_2): Binary(op_1, op_2) {} 
    std::string get_sign() const { return " * "; }
    Expression* diff(std::string var) { 
      return new Add(new Mult(op_1->diff(var), op_2->copy()), new Mult(op_1->copy(), op_2->diff(var))); 
    }
    Expression* copy() { 
      return new Mult(op_1->copy(), op_2->copy());  
    }
};

class Div: public Binary {
  public:
    Div(Expression* op_1, Expression* op_2): Binary(op_1, op_2) {} 
    std::string get_sign() const { return " / "; }
    Expression* diff(std::string var) { 
      Expression* up = new Sub(new Mult(op_1->diff(var), op_2->copy()), new Mult(op_1->copy(), op_2->diff(var))); 
      Expression* down = new Mult(op_2->copy(), op_2->copy());
      return new Div(up, down); 
    }
    Expression* copy() { 
      return new Div(op_1->copy(), op_2->copy());  
    }
};


class Exponent: public Unary {
  public:
    Exponent(Expression* op): Unary(op) {} 
    explicit operator std::string() const { 
      return "e^" + static_cast<std::string>(*op); 
    }
    Expression* diff(std::string var) { 
      return new Mult(op->diff(var), this->copy()); 
    }
    Expression* copy() { 
      return new Exponent(op->copy());  
    }
};


class Val: public Expression {
    int num;
  public:
    Val(int num): num(num) {}
    explicit operator std::string() const { 
      return std::to_string(num); 
    }
    Expression* diff(std::string var) {
      return new Val(0);
    }
    Expression* copy() { 
      return new Val(num);  
    }
};

class Var: public Expression {
    std::string variable;
  public:
    Var(std::string var): variable(var) {}
    explicit operator std::string() const { 
      return variable; 
    }
    Expression* diff(std::string var) {
      if (variable == var) {
          return new Val(1);
      }
      return new Val(0);
    }
    Expression* copy() { 
      return new Var(variable);  
    }
};
