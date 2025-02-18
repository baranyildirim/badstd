#include "badstd/shared_ptr.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "badstd/instance_counter.h"

TEST(SharedPtrTest, Constructor) {
  {
    auto shared_ptr = SharedPtr<InstanceCounter>{new InstanceCounter()};
    EXPECT_EQ(InstanceCounter::Count(), 1);
  }
  EXPECT_EQ(InstanceCounter::Count(), 0);
}

TEST(SharedPtrTest, CopyConstructor) {
  {
    auto shared_ptr = SharedPtr<InstanceCounter>{new InstanceCounter()};
    EXPECT_EQ(InstanceCounter::Count(), 1);
    SharedPtr shared_ptr_copy(shared_ptr);
    EXPECT_EQ(InstanceCounter::Count(), 1);
  }
  EXPECT_EQ(InstanceCounter::Count(), 0);
}

TEST(SharedPtrTest, MoveConstructor) {
  {
    auto shared_ptr = SharedPtr<InstanceCounter>{new InstanceCounter()};
    EXPECT_EQ(InstanceCounter::Count(), 1);
    SharedPtr shared_ptr_copy(std::move(shared_ptr));
    EXPECT_EQ(InstanceCounter::Count(), 1);
  }
  EXPECT_EQ(InstanceCounter::Count(), 0);
}