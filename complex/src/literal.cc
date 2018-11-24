#include <complex>
#include <iostream>

int main() {
  using namespace std::complex_literals;
  std::complex<double> z = 2.0i;
  std::cout << z << std::endl;

  return 0;
}
