#include <cmath>
#include <iostream>
#include <limits>

int main() {
  constexpr double kPositiveZero = +0;
  constexpr double kNegativeZero = -0;

  constexpr double kPositiveOne = +1;
  constexpr double kNegativeOne = -1;

  constexpr double kPositiveInfinity = +std::numeric_limits<double>::infinity();
  constexpr double kNegativeInfinity = -std::numeric_limits<double>::infinity();

  std::cout << std::boolalpha;

  std::cout << "=== NaN (Quite NaN or Signaling NaN) ===" << std::endl;
  std::cout << "+0 / +0 = " << (kPositiveZero / kPositiveZero) << std::endl;
  std::cout << "sqrt(-1) = " << std::sqrt(kNegativeOne) << std::endl;

  std::cout << "=== Divided by signed zero -> signed infinity ===" << std::endl;
  std::cout << "+1 / +0 = " << (kPositiveOne / kPositiveZero) << std::endl;
  std::cout << "-1 / +0 = " << (kNegativeOne / kPositiveZero) << std::endl;
  std::cout << "+1 / -0 = " << (kPositiveOne / kNegativeZero) << std::endl;
  std::cout << "-1 / -0 = " << (kNegativeOne / kNegativeZero) << std::endl;

  std::cout << "=== Compare +0 and -0 -> true ===" << std::endl;
  std::cout << "(+0 == -0) = " << (kPositiveZero == kNegativeZero) << std::endl;

  std::cout << "=== Divided by signed infinity ===" << std::endl;
  std::cout << "+1 / +inf = " << (kPositiveOne / kPositiveInfinity)
            << std::endl;
  std::cout << "-1 / +inf = " << (kNegativeOne / kPositiveInfinity)
            << std::endl;
  std::cout << "+1 / -inf = " << (kPositiveOne / kNegativeInfinity)
            << std::endl;
  std::cout << "-1 / -inf = " << (kNegativeOne / kNegativeInfinity)
            << std::endl;

  return 0;
}
