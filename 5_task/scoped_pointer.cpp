#include <iostream>
#include <optional>

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

    std::optional<T> get() { 
      if (pointer) return *pointer;
      return std::nullopt; 
    }
        
    const std::optional<T> get() const { 
      if (pointer) return *pointer;
      return std::nullopt;
    }

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

    ScopedPointerV2& operator=(ScopedPointerV2&& other) {    // move assignment operator   
      if (this != &other) { 
        delete pointer;                              
        pointer = other.pointer;
        other.pointer = nullptr;
      }             
      return *this;
    }

    T* operator->() { return pointer; }
    const T* operator->() const { return pointer; }


    std::optional<T> get() { 
      if (pointer) return *pointer;
      return std::nullopt; 
    }
        
    const std::optional<T> get() const { 
        if (pointer) return *pointer;
        return std::nullopt;
    }

    ~ScopedPointerV2() { delete pointer; }
};


struct Point { 
    double x, y; 
};
