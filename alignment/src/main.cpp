#include "util.hpp"

#define ShowSizeofAndAlignof(TYPENAME)                         \
  do {                                                         \
    std::cout << #TYPENAME << ": " << sizeof(TYPENAME) << ", " \
              << alignof(TYPENAME) << std::endl;               \
  } while (false)

struct Hoge {
  char c[63];
  short s;
  double i;

  Hoge() { std::memset(this, 0, sizeof(*this)); }
};

struct Fuga {
  char c1;
  int i;
  char c2;
  double d;

  Fuga() { std::memset(this, 0, sizeof(*this)); }
};

struct Empty {};

void ShowTypeInfo() {
  std::cout << "typename: sizeof, alignof" << std::endl;
  ShowSizeofAndAlignof(char);
  ShowSizeofAndAlignof(short);
  ShowSizeofAndAlignof(int);
  ShowSizeofAndAlignof(long);
  ShowSizeofAndAlignof(long long);
  ShowSizeofAndAlignof(float);
  ShowSizeofAndAlignof(double);
  ShowSizeofAndAlignof(long double);
  ShowSizeofAndAlignof(void*);
  ShowSizeofAndAlignof(Empty);
  ShowSizeofAndAlignof(Hoge);
}

int main() {
  std::cout << "[ShowTypeInfo]" << std::endl;
  ShowTypeInfo();
  std::cout << std::endl;

  std::cout << "[u64t]" << std::endl;
  std::uint64_t u64t = 0x0123456789abcdef;
  PrintMemory(u64t);
  std::cout << "u64t = " << u64t << std::endl;
  std::cout << std::endl;

  std::cout << "[h1]" << std::endl;
  Hoge h1;
  {
    auto p = reinterpret_cast<char*>(&h1.c);
    p[0] = 0x12;
    p[1] = 0x34;
    for (auto i = 2; i < 61; ++i) {
      p[i] = 0x55;
    }
    p[61] = 0x67;
    p[62] = 0x89;
  }
  PrintMemory(h1);
  std::cout << std::endl;

  std::cout << "[h2]" << std::endl;
  Hoge h2;
  {
    auto p = reinterpret_cast<char*>(&h2.s);
    p[0] = 0x12;
    p[1] = 0x34;
  }
  PrintMemory(h2);
  std::cout << "s = " << h2.s << std::endl;
  std::cout << std::endl;

  std::cout << "[h3]" << std::endl;
  Hoge h3;
  {
    auto p = reinterpret_cast<char*>(&h3.i);
    p[0] = 0x12;
    p[1] = 0x34;
    p[2] = 0x55;
    p[3] = 0x55;
    p[4] = 0x55;
    p[5] = 0x55;
    p[6] = 0x67;
    p[7] = 0x89;
  }
  PrintMemory(h3);
  std::cout << "i = " << h3.i << std::endl;

  Fuga f;
  f.c1 = 0xaa;
  {
    auto p = reinterpret_cast<char*>(&f.i);
    p[0] = 0x12;
    p[1] = 0x34;
    p[2] = 0x56;
    p[3] = 0x78;
  }
  f.c2 = 0xbb;
  {
    auto p = reinterpret_cast<char*>(&f.d);
    p[0] = 0x12;
    p[1] = 0x34;
    p[2] = 0x55;
    p[3] = 0x55;
    p[4] = 0x55;
    p[5] = 0x55;
    p[6] = 0x67;
    p[7] = 0x89;
  }
  PrintMemory(f);

  return 0;
}
