#pragma once

#include <array>
#include <mutex>

template <typename T, size_t Size>
class CircularBuffer {
public:
    CircularBuffer() : head(0), tail(0), full(false) {}

    bool push(const T& item) {
        std::lock_guard<std::mutex> lock(mutex);

        if (full) return false;

        buffer[tail] = item;
        tail = (tail + 1) % Size;

        if (tail == head) full = true;

        return true;
    }

    bool pop(T& out) {
        std::lock_guard<std::mutex> lock(mutex);

        if (empty()) return false;

        out = buffer[head];
        head = (head + 1) % Size;
        full = false;
        return true;
    }

    bool empty() const {
        return (!full && head == tail);
    }

    bool isFull() const {
        return full;
    }

private:
    std::array<T, Size> buffer;
    size_t head;
    size_t tail;
    bool full;
    mutable std::mutex mutex;
};
