#include <iostream>
#include <typeinfo>

#define SHOW_INFO(_TYPE) (show_info_impl<_TYPE>(#_TYPE))

template <typename T>
void show_info_impl(const char* type_name) {
  std::cout << "[" << type_name << "]" << std::endl;
  std::cout << "size: " << sizeof(T) << std::endl;
  std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
  std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
}

int main() {
  SHOW_INFO(float);
  SHOW_INFO(double);
  SHOW_INFO(long double);

  return 0;
}
