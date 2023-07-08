
#pragma once

#include <ctime>
#include <vector>

#include "./Price.h"

namespace hftbox::orders {

/*
 * OrderBook tracks orders for a particular symbol.
 */
struct OrderBook {
  std::vector<Price> price;
  std::vector<std::time_t> time;
};

}  // namespace hftbox::orders