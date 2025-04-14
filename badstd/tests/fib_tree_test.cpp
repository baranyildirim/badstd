
#include "badstd/fib_tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FibTreeTest, FindPath) { EXPECT_EQ(find_path(5, 5, 7), "UUURL"); }
