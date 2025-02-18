#pragma once

#include <optional>
#include <vector>

template <class T>
class RingBufferQueue {
  RingBufferQueue(int capacity) : capacity_(capacity), queue_(capacity, T{}) {}

  bool Push(const T& t) {
    if (IsFull()) return false;
    queue_[tail_] = t;
    ++tail_;
    return false;
  }

  std::optional<T> Pop(const T& t) {
    if (IsEmpty()) return std::nullopt;
    auto element = queue_[head_ % capacity_];
    ++head_;
    return element;
  }

  bool IsFull() { return (tail_ - head_) == capacity_; }
  bool IsEmpty() { return tail_ == head_; }

 private:
  int capacity_;
  std::vector<T> queue_;
  int head_{0};
  int tail_{0};
};