
#pragma once

#include <ctime>
#include <string>
#include <unordered_map>
#include <vector>

#include "hftbox/orders/Order.h"
#include "hftbox/orders/OrderBook.h"

namespace hftbox::orders {

/*
 * MatchingEngine emits events when a a buy and sell order can be matched.
 * Each symbol being traded has its own matching engine.
 * MatchingEngine is meant to subscribe to orders for that symbol.
 */
class MatchingEngine {
 public:
  void on_order(Order order);

 private:
  OrderBook market_orders_;
};

}  // namespace hftbox::orders