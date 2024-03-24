#include <iostream>

template<typename T>
class ScopedPointer {
    T* pointer;
  public:
    ScopedPointer(T* raw): pointer(raw) { }
    ScopedPointer(const ScopedPointer& other) {         // copy constructor 
        T data = *other.pointer;
        pointer = new T(data);                          // call copy ctr of type T
    }

    ScopedPointer(ScopedPointer&& other) {              // move constructor 
        pointer = other.pointer;
        other.pointer = nullptr;
    }

    ScopedPointer& operator=(ScopedPointer other) {     // copy and swap  
      std::swap(pointer, other.pointer);              
      return *this;
    }

    T* operator->() { return pointer; }
    const T* operator->() const { return pointer; }

    ~ScopedPointer() { delete pointer; }
};


template<typename T>
class ScopedPointerV2 {
    T* pointer;
  public:
    ScopedPointerV2(T* raw): pointer(raw) { }

    ScopedPointerV2(const ScopedPointerV2& other) = delete;  // copy constructor prohibited

    ScopedPointerV2(ScopedPointerV2&& other) {               // move constructor 
        pointer = other.pointer;
        other.pointer = nullptr;
    }

    ScopedPointerV2& operator=(ScopedPointerV2&& other) {   // call only move constructor   
      if (this != &other) {                                 // try to copy - compilation error (prohibited)
        std::swap(pointer, other.pointer);
      }             
      return *this;
    }

    T* operator->() { return pointer; }
    const T* operator->() const { return pointer; }

    ~ScopedPointerV2() { delete pointer; }
};


struct Point { 
    double x, y; 
};



int main(int argc, char **argv)
{
    // copy ctr 
    ScopedPointer sp_0 = ScopedPointer(new Point{2, 3});
    ScopedPointer sp_1 = sp_0;
    sp_1->x = 9;
    std::cout << sp_0->x  << sp_0->y << std::endl;
    std::cout << sp_1->x  << sp_1->y << std::endl;

    // move ctr
    ScopedPointer sp_2 = std::move(sp_0);
    std::cout << sp_2->x  << sp_2->y << std::endl;

    // move assignment operator
    ScopedPointer sp_3 = ScopedPointer(new Point{1, 1});
    sp_3 = std::move(sp_1);
    std::cout << sp_3->x  << sp_3->y << std::endl;

  
    // move ctr v2
    ScopedPointerV2 sp_4 = ScopedPointerV2(new Point{4, 4});
    ScopedPointerV2 sp_5= std::move(sp_4);
    std::cout << sp_5->x  << sp_5->y << std::endl;

    // move assignment operator v2
    ScopedPointerV2 sp_6 = ScopedPointerV2(new Point{1, 1});
    ScopedPointerV2 sp_7 = ScopedPointerV2(new Point{2, 2});
    sp_7 = std::move(sp_6);
    std::cout << sp_7->x  << sp_7->y << std::endl;
}