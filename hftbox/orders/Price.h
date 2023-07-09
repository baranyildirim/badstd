
#pragma once

#include <ctime>

namespace hftbox::orders {

/*
 * Price is a double-like type that mitigates rounding-errors.
 * This is done using the improved Kahan summation.
 */
using Price = double;

}  // namespace hftbox::orders