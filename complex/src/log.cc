#include <complex>
#include <iostream>

int main() {
  std::complex<double> z(-std::exp(2.0), 0);
  std::cout << std::log(z) << std::endl;
  return 0;
}
