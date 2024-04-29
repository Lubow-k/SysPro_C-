#pragma once


template <typename T, int limit>
struct Counter {
    inline static int objects_created = 0;

    Counter() {
        if (objects_created >= limit) {
            throw std::runtime_error("Instance limit exceeded");
        }
        ++objects_created;
    }
    Counter(const Counter&) {
        ++objects_created;
    }
  protected:
    ~Counter() {
        --objects_created;
    }
};
