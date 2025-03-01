#pragma once
#include <atomic>

class InstanceCounter {
 public:
  InstanceCounter();
  ~InstanceCounter();

  InstanceCounter(const InstanceCounter& other);
  InstanceCounter& operator=(const InstanceCounter& other);

  static int Count();

 private:
  static inline std::atomic<int> counter_{0};
};