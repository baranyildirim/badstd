#pragma once

namespace hftbox::orders {

enum class OrderKind {
  kMarketOrder = 0,
  kLimitOrder,
  kStopOrder,
  kIcebergOrder,
  kFillOrKillOrder,
  kGorillaOrder,
  kPeggedOrder,
  kDiscretionaryOrder,
};

struct Order {
  OrderKind kind;
};

}  // namespace hftbox::orders