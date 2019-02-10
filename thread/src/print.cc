#include "print.h"

#include <iostream>
#include <mutex>

std::mutex print_mutex;

void Print(const std::string& s) {
  std::lock_guard<std::mutex> lock(print_mutex);
  std::cout << s << std::endl;
}
