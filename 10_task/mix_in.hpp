#pragma once


template <typename T, int limit>
struct Counter {
    inline static int objects_created = 0;

    instanceChecker() {
        if (objects_created >= limit) {
            throw std::runtime_error("Instance limit exceeded");
        }
    }

    Counter() {
        instanceChecker();
        ++objects_created;
    }

    Counter(const Counter&) {
        instanceChecker();
        ++objects_created;
    }
  protected:
    ~Counter() {
        --objects_created;
    }
};
