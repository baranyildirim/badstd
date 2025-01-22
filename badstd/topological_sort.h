#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using Edge = std::pair<int, int>;
using EdgeList = std::vector<Edge>;

inline std::vector<int> sort(const EdgeList& graph) {
  auto node_deps = std::unordered_map<int, std::unordered_set<int>>{};
  auto node_edges = std::unordered_map<int, std::unordered_set<int>>{};
  for (const auto& [from, to] : graph) {
    node_deps[to].insert(from);
    if (!node_deps.contains(from)) node_deps[from] = {};
    node_edges[from].insert(to);
    if (!node_edges.contains(to)) node_edges[to] = {};
  }
  auto start_nodes = std::queue<int>{};
  for (const auto& [node, deps] : node_deps) {
    if (deps.empty()) start_nodes.push(node);
  }
  auto solution = std::vector<int>{};
  while (!start_nodes.empty()) {
    auto curr_node = start_nodes.front();
    start_nodes.pop();
    solution.push_back(curr_node);

    auto neighbors = node_edges[curr_node];
    for (const auto neighbor : neighbors) {
      node_edges[curr_node].erase(neighbor);
      node_deps[neighbor].erase(curr_node);
      if (node_deps[neighbor].empty()) start_nodes.push(neighbor);
    }
  }
  return std::all_of(
             node_deps.begin(), node_deps.end(),
             [](const auto& nodeAndDeps) { return nodeAndDeps.second.empty(); })
             ? solution
             : std::vector<int>{};
}
