#include "badstd/instance_counter.h"

InstanceCounter::InstanceCounter() { ++InstanceCounter::counter_; }
InstanceCounter::~InstanceCounter() { --InstanceCounter::counter_; }

InstanceCounter::InstanceCounter(const InstanceCounter& other) {
  ++InstanceCounter::counter_;
}

InstanceCounter& InstanceCounter::operator=(const InstanceCounter& other) {
  ++InstanceCounter::counter_;
  return *this;
}

int InstanceCounter::Count() { return InstanceCounter::counter_; }