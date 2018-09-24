#include <vector>

class Hoge : public std::vector<int> {
 public:
  Hoge() { this->push_back(0); }

  virtual ~Hoge() = default;
};

int main() {
  Hoge hoge;

  return 0;
}
