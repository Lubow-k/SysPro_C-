#include <new>
#include <iostream>
#include<type_traits>


class Pair {
private:
    int first, second;

public:
    Pair(int f, int s) : first(f), second(s) {}

    Pair(const Pair& other) : first(other.first), second(other.second) {}

    int getFirst() const { return first; }
    int getSecond() const { return second; }
};



template<size_t SIZE, typename... Types>
void allocate(void* memory, Types... args) {
  constexpr size_t total_size = (sizeof(Types) + ...) ;
  static_assert(SIZE >= total_size);
  static_assert((std::is_copy_constructible<Types>::value && ...));
  auto buffer = static_cast<char*>(memory);
  bool ok = (((new (buffer) Types(args)) ? (buffer += sizeof(Types), true) : (false)) && ...);
}

int main() {

  char memory[sizeof(int) + sizeof(double) + sizeof(std::string)];   // 4 + 8 + 24 = 36 

  allocate<sizeof(memory)>(memory, 10, 3.14, std::string("Hello"));


  int* buf_1 = (int*) (memory); 
  double* buf_2 = (double*) (memory + sizeof(int)); 
  std::string* buf_3 = (std::string*) (memory + sizeof(int) + sizeof(double)); 

  std::cout << *buf_1 << std::endl; 
  std::cout << *buf_2 << std::endl; 
  std::cout << *buf_3 << std::endl; 

  return 0;
}
