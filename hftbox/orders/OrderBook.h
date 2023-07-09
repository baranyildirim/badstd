
#pragma once

#include <ctime>
#include <vector>

#include "hftbox/orders/Price.h"

namespace hftbox::orders {

struct OrderBookList {
  std::vector<Price> price;
  std::vector<std::time_t> time;
};

/*
 * OrderBook tracks orders for a particular symbol.
 */
struct OrderBook {
  OrderBookList buy_orders;
  OrderBookList sell_orders;

  void add_buy_order(const Price price) {
    buy_orders.price.push_back(price);
    buy_orders.time.push_back(time(0));
  };

  void add_sell_order(const Price price) {
    sell_orders.price.push_back(price);
    sell_orders.time.push_back(time(0));
  };
};

}  // namespace hftbox::orders