#include <unistd.h>

#include <functional>
#include <iostream>
#include <sstream>
#include <thread>

#include "print.h"

void Piyo(const int times, const int interval) {
  for (auto i = 0; i < times; ++i) {
    sleep(interval);
    std::stringstream ss;
    ss << __func__ << "(" << times << ", " << interval << ")";
    Print(ss.str());
  }
}

int main() {
  std::thread hoge(Piyo, 5, 2);
  std::thread fuga(Piyo, 3, 3);

  hoge.join();
  fuga.join();

  return 0;
}
