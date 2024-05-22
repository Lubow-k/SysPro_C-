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
  auto alloc = [&buffer]<typename T>(T arg) { 
    new(buffer) T(arg); 
    buffer += sizeof(T);  
  }; 

  ((alloc(args)), ...);
}

int main() {
  int v_1 = 3;
  double v_2 = 3.14;
  std::string v_3 = "SysPro";
  Pair v_4(1, 2);

  const size_t memory_size = sizeof(v_1) + sizeof(v_2) + sizeof(v_3) + sizeof(v_4);
  char memory[memory_size]; 

  allocate<memory_size>(memory, v_1, v_2, v_3, v_4);

  int* buf_1 = (int*) (memory); 
  double* buf_2 = (double*) (memory + sizeof(v_1)); 
  std::string* buf_3 = (std::string*) (memory + sizeof(v_1) + sizeof(v_2)); 
  Pair* buf_4 = (Pair*) (memory + sizeof(v_1) + sizeof(v_2) + sizeof(v_3)); 

  std::cout << *buf_1 << std::endl; 
  std::cout << *buf_2 << std::endl; 
  std::cout << *buf_3 << std::endl; 
  std::cout << buf_4->getFirst() << " " << buf_4->getSecond() << std::endl; 

  return 0;
}
