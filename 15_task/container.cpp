#include <new>
#include <iostream>
#include <cassert>
#include <type_traits>



class Pair {
private:
    int first, second;
public:
    Pair(int f, int s) : first(f), second(s) {}
    Pair(const Pair& other) : first(other.first), second(other.second) {}
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    ~Pair() {
        std::cout << "in dstr" << std::endl;
    }
};



template<size_t SIZE, typename... Types>
void allocate(void* memory, Types... args) requires ((std::is_copy_constructible<Types>::value && ...), (SIZE >= (sizeof(Types) + ...))) {
  auto buffer = static_cast<char*>(memory);
  auto alloc = [&buffer]<typename T>(T arg) { 
    new(buffer) T(arg); 
    buffer += sizeof(T);  
  }; 

  ((alloc(args)), ...);
}

template<typename... Types>
class Container {
    char memory[(sizeof(Types) + ...)];
    size_t shifts[sizeof...(Types)];

  public:
    Container(Types... args) { 
        allocate<sizeof(memory)>(memory, args...);
        int i = 0, index = 0;
        auto fill_shifts = [&i, &index, this]<typename T>(T arg) { 
            shifts[index++] = i;
            i += sizeof(T);
        }; 
        ((fill_shifts(args)), ...);
    }

    template<typename T>
    T getElement(size_t idx) {
      return *((T*) (memory + shifts[idx]));
    }

    ~Container() {
        std::cout << "in container dstr" << std::endl;
    }
};


int main() {
    {

        Container<int, char, Pair> container(12, 'A', Pair(44, 33));

        std::cout << container.getElement<int>(0) << std::endl;
        std::cout << container.getElement<char>(1) << std::endl;

        std::cout << container.getElement<Pair>(2).getFirst() << std::endl;
        std::cout << container.getElement<Pair>(2).getSecond() << std::endl;

    }

    std::cout << "end" << std::endl;

}