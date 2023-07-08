
#pragma once

#include <ctime>

namespace hftbox::orders {

/*
 * Price is a double-like type that mitigates rounding-errors.
 * This is done using Kahan summation.
 */
struct Price {};

}  // namespace hftbox::orders