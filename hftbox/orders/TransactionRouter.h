#pragma once

#include <unordered_map>

#include "hftbox/fix/Frame.h"
#include "hftbox/orders/MatchingEngine.h"

namespace hftbox::orders {

class TransactionRouter {
 public:
  void receive(FixFrame frame);
  void send(FixFrame frame);

 private:
  std::unordered_map<std::string, MatchingEngine> engines_;
};

}  // namespace hftbox::orders
