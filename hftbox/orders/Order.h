#pragma once

#include <string>

namespace hftbox::orders {

enum class OrderKind {
  kMarketOrder = 0,
  kLimitOrder,
  kStopOrder,
  kStopLimitOrder,
  kTrailingStopOrder
};

enum class OrderInstruction {
  kDay = 0,
  kGoodTilCanceled,
  ImmediateOrCancel,
  FillOrKill,
  AllOrNone,
  OnOpen,
  OnClose
};

using Symbol = std::string;

struct Order {
  OrderKind kind;
  OrderInstruction instruction;
};

}  // namespace hftbox::orders