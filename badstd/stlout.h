#pragma once

#include <string>
#include <vector>

template <class T1, class T2>
std::string to_string(const std::vector<std::pair<T1, T2>>& v) {
  auto out = std::string{'['};
  for (const auto& [first, second] : v) {
    out +=
        '(' + std::to_string(first) + "," + std::to_string(second) + ')' + ',';
  }
  if (!v.empty()) out.pop_back();
  out += ']';
  return out;
}

template <class T>
std::string to_string(const std::vector<T>& v) {
  auto out = std::string{'['};
  for (const auto& e : v) {
    out += std::to_string(e) + ',';
  }
  if (!v.empty()) out.pop_back();
  out += ']';
  return out;
}