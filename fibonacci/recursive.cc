#include <iostream>

int Fibonacchi(const int n) {
  switch (n) {
  case 0:
    return 0;
  case 1:
    return 1;
  default:
    return Fibonacchi(n - 1) + Fibonacchi(n - 2);
  }
}

int main() {
  constexpr const int kNumber = 40;
  std::cout << Fibonacchi(kNumber) << std::endl;
  return 0;
}
