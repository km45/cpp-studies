#include <unistd.h>

#include <iostream>
#include <thread>

void Hoge() {
  for (auto i = 0; i < 5; ++i) {
    sleep(2);
    std::cout << __func__ << std::endl;
  }
}

void Fuga() {
  for (auto i = 0; i < 3; ++i) {
    sleep(3);
    std::cout << __func__ << std::endl;
  }
}

int main() {
  std::thread hoge(Hoge);
  std::thread fuga(Fuga);

  hoge.join();
  fuga.join();

  return 0;
}
