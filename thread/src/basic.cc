#include <unistd.h>

#include <iostream>
#include <thread>

#include "print.h"

void Hoge() {
  for (auto i = 0; i < 5; ++i) {
    sleep(2);
    Print(__func__);
  }
}

void Fuga() {
  for (auto i = 0; i < 3; ++i) {
    sleep(3);
    Print(__func__);
  }
}

int main() {
  std::thread hoge(Hoge);
  std::thread fuga(Fuga);

  hoge.join();
  fuga.join();

  return 0;
}
