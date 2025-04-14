#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "badstd/stlout.h"
#include "badstd/string.h"

/**
 * Find path from source node to destination node in a fibonacci tree.
 *
 * A fibonacci tree has a left subtree of order n-2, and a right subtree of
 * order n-1.
 *
 * Nodes are labelled in a pre-order way (root, left, right), with the
 * root starting at 0.
 *
 * A fibonacci tree of order 5 is as follows (with values):
 *                        5
 *                   /        \
 *                  2            3
 *                 / \        /    \
 *                1   1      1      2
 *                   / \    / \    / \
 *                  0   1  0   1  1   1
 *                                   / \
 *                                  0   1
 * A fibonacci tree of order 5 is as follows (with labels):
 *                        0
 *                   /        \
 *                  1            6
 *                 / \        /    \
 *                2   3      7     10
 *                   / \    / \    / \
 *                  4   5  8   9  11  12
 *                                   / \
 *                                  13  14
 */
inline std::string find_path(const int order, const int src_label,
                             const int dst_label) {
  auto nodes_in_subtree = std::vector(order + 1, 1);
  for (int i = 2; i <= order; ++i) {
    nodes_in_subtree[i] = nodes_in_subtree[i - 1] + nodes_in_subtree[i - 2] + 1;
  }
  std::cout << to_string(nodes_in_subtree) << std::endl;
  auto find_path_recursive =
      [&nodes_in_subtree = std::as_const(nodes_in_subtree)](
          auto self, const int curr_node_label, const int curr_tree_order,
          const int target_label) -> std::string {
    if (curr_node_label == target_label) {
      return std::string{};
    }
    const auto left_nodes_count = nodes_in_subtree.at(curr_tree_order - 2);
    if (curr_node_label + left_nodes_count >= target_label) {
      return "L" +
             self(self, curr_node_label + 1, curr_tree_order - 2, target_label);
    } else {
      return "R" + self(self, curr_node_label + left_nodes_count + 1,
                        curr_tree_order - 1, target_label);
    }
  };
  auto src_path_from_root =
      find_path_recursive(find_path_recursive, 0, order, src_label);
  auto dst_path_from_root =
      find_path_recursive(find_path_recursive, 0, order, dst_label);
  remove_common_prefix(src_path_from_root, dst_path_from_root);
  return std::string(src_path_from_root.size(), 'U') + dst_path_from_root;
}
