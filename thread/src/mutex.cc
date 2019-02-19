#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

struct SharedResource {
  SharedResource() = default;
  int count = 0;
};

void Add1(SharedResource* r) {
  r->count += 1;
}

void Add2(SharedResource* r) {
  static std::mutex m;
  m.lock();
  {
    auto c = r->count;
    r->count = c + 1;
  }
  m.unlock();
}

void Test(const std::function<void(SharedResource*)> f) {
  SharedResource r;

  constexpr int kThreads = 100;
  constexpr int kLoopTimes = 2000;

  for (auto j = 0; j < kLoopTimes; ++j) {
    std::vector<std::thread> workers;

    for (auto i = 0; i < kThreads; ++i) {
      workers.emplace_back(std::thread(f, &r));
    }

    for (auto& worker : workers) {
      worker.join();
    }
  }

  std::cout << r.count << std::endl;
}

int main() {
  Test(Add1);
  Test(Add2);
  return 0;
}
