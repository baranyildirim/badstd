#pragma once

#include <atomic>

template <class T>
class SharedPtr {
 public:
  SharedPtr(T* ptr) : blk(new ControlBlock{ptr}) {}
  ~SharedPtr() {
    Dispose();
    blk = nullptr;
  }

  SharedPtr(const SharedPtr& other) {
    blk = other.blk;
    IncrementCount();
  }

  SharedPtr& operator=(const SharedPtr& other) {
    if (this == &other) {
      IncrementCount();
    } else {
      Dispose();
      blk = other.blk;
      IncrementCount();
    }
    return *this;
  }

  SharedPtr& operator=(SharedPtr&& other) {
    if (this == &other) return *this;
    Dispose();
    blk = other.blk;
    other.blk = nullptr;
    return *this;
  }

  SharedPtr(SharedPtr&& other) {
    blk = other.blk;
    other.blk = nullptr;
  }

  SharedPtr* operator*() { return blk->ptr; }
  SharedPtr* operator->() { return blk->ptr; }

 protected:
  void Dispose() {
    if (blk != nullptr) {
      --(blk->count);
      if (blk->count == 0) {
        delete blk->ptr;
        delete blk;
      }
    }
  }

  void IncrementCount() {
    if (blk != nullptr) {
      ++(blk->count);
    }
  }

 private:
  class ControlBlock {
   public:
    T* ptr{nullptr};
    std::atomic<int> count{1};
  };

  ControlBlock* blk{nullptr};
};