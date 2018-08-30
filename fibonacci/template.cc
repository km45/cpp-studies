#include <iostream>

template <int N> int Fibonacchi() {
  return Fibonacchi<N - 1>() + Fibonacchi<N - 2>();
}

template <> int Fibonacchi<0>() { return 0; }

template <> int Fibonacchi<1>() { return 1; }

int main() {
  constexpr const int kNumber = 40;
  std::cout << Fibonacchi<kNumber>() << std::endl;
  return 0;
}
