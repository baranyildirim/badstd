#pragma once

#include <atomic>

template <class T>
class ControlBlock {
  T* ptr{nullptr};
  std::atomic<int> count{1};
};

template <class T>
class SharedPtr {
 public:
  SharedPtr(T* ptr) : blk(new ControlBlock<T>(ptr)) {}
  ~SharedPtr() { Dispose(); }

  SharedPtr& operator=(const SharedPtr& other) {
    if (this == &other) return *this;
    Dispose();
    blk = other;
    blk->count++;
    return *this;
  }

  SharedPtr& operator=(SharedPtr&& other) {
    if (this == &other) {
      other.blk = nullptr;
      return *this;
    }
    Dispose();
    blk->count++;
    return *this;
  }

  SharedPtr* operator*() { return blk->ptr; }
  SharedPtr* operator->() { return blk->ptr; }

  void Dispose() {
    if (blk != nullptr) {
      blk->count--;
      if (blk->count == 0) {
        delete blk->ptr;
        delete blk;
      }
    }
  }

 private:
  ControlBlock<T>* blk{nullptr};
};