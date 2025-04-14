#pragma once

#include <string>

#include "badstd/string.h"

inline long ipv4_to_long(const std::string& ipv4) {
  long num = 0;
  auto parts = split<std::vector<std::string>>(ipv4, "\\.");
  for (const auto& p : parts) {
    num = 256 * num + std::stoi(p);
  }
  return num;
}
