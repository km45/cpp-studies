#include <iostream>

struct Point {
  Point() = default;

  Point(const int x, const int y) : x(x), y(y) {}

  int x;
  int y;
};

template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const Point& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}
