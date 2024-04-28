#include "StringRWBuffer.hpp"



bool StringRWBuffer::append_to_resource() {
    int pos = get_write();
    for (size_t i = 0; i < pos; i++) {
        source += buffer_write[i];
    }
    zero_write();
    return pos > 0;
}

bool StringRWBuffer::get_from_resource() {
    // may be ret how many chars read
    for (size_t i = 0; i < buffer_size; i++) {
        if (it == source.end() && i == 0) {
            if (append_to_resource()) { return get_from_resource(); }
            return false;
        }
        buffer_read[i] = *it++;
    }
    return true;
}

