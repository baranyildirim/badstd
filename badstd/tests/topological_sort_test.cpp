
#include "badstd/topological_sort.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "badstd/stlout.h"

TEST(TopologicalSortTest, RegularGraph) {
  auto edges = EdgeList{Edge{0, 1}, Edge{1, 2}};
  auto solution = sort(edges);
  EXPECT_THAT(solution, testing::Eq(std::vector<int>{0, 1, 2}));
}
