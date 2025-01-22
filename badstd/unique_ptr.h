#pragma once

#include <utility>

template <class T>
class UniquePtr {
 public:
  explicit UniquePtr(T* value) { ptr = value; }
  ~UniquePtr() { delete ptr; }

  template <class... Args>
  UniquePtr(Args&&... args) {
    ptr = new T(std::forward<Args>(args)...);
  };

  UniquePtr(const UniquePtr& other) = delete;
  UniquePtr& operator=(const UniquePtr& other) = delete;

  UniquePtr(UniquePtr&& other) noexcept { std::swap(other.ptr, ptr); }
  UniquePtr& operator=(UniquePtr&& other) noexcept {
    std::swap(other.ptr, ptr);
  }

  T* operator->() const noexcept { return ptr; }
  T* Get() const noexcept { return ptr; }

 private:
  T* ptr{nullptr};
};