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

inline std::vector<std::vector<int>> sort_all(const EdgeList& graph) {
  auto node_deps = std::unordered_map<int, std::unordered_set<int>>{};
  auto node_edges = std::unordered_map<int, std::unordered_set<int>>{};
  for (const auto& [from, to] : graph) {
    node_deps[to].insert(from);
    node_deps[from];
    node_edges[from].insert(to);
    node_edges[to];
  }
  auto start_nodes = std::queue<int>{};
  for (const auto& [node, deps] : node_deps) {
    if (deps.empty()) start_nodes.push(node);
  }
  auto all_sorts = std::vector<std::vector<int>>{};
  const auto sort_all_recursive = [&all_sorts](const auto& self, auto solution,
                                               auto start_nodes, auto node_deps,
                                               auto node_edges) -> void {
    auto seen_nodes = std::unordered_set<int>{};
    while (!start_nodes.empty()) {
      auto curr_node = start_nodes.front();
      if (seen_nodes.contains(curr_node)) break;
      seen_nodes.insert(curr_node);
      start_nodes.pop();
      auto curr_start_nodes = start_nodes;
      start_nodes.push(curr_node);

      auto curr_solution = solution;
      curr_solution.push_back(curr_node);

      auto curr_node_deps = node_deps;
      auto curr_node_edges = node_edges;

      const auto neighbors = curr_node_edges[curr_node];
      for (const auto neighbor : neighbors) {
        curr_node_deps[neighbor].erase(curr_node);
        curr_node_edges[curr_node].erase(neighbor);
        if (curr_node_deps[neighbor].empty()) {
          curr_start_nodes.push(neighbor);
        }
      }
      self(self, curr_solution, curr_start_nodes, curr_node_deps,
           curr_node_edges);
    }
    if (std::all_of(
            node_deps.begin(), node_deps.end(),
            [](const auto& nodeAndDeps) { return nodeAndDeps.second.empty(); }))
      all_sorts.push_back(solution);
  };
  sort_all_recursive(sort_all_recursive, std::vector<int>{}, start_nodes,
                     node_deps, node_edges);
  return all_sorts;
}