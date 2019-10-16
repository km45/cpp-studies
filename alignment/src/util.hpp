#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
inline void PrintMemory(T&& v) {
  auto p = reinterpret_cast<const unsigned char* const>(&v);
  std::vector<std::string> bytes;

  for (auto i = 0u; i < sizeof(T); ++i) {
    char byte[3];
    std::sprintf(byte, "%02x", p[i]);
    bytes.push_back(byte);
  }

  std::cout << "  01234567 89abcdef" << std::endl;
  std::cout << " +--------+--------+" << std::endl;
  for (auto i = 0u; i < bytes.size(); ++i) {
    if (i % 8 == 0) {
      std::cout << (i / 8) << "|";
    }
    std::cout << bytes[i];
    if (i % 8 == 3) {
      std::cout << "|";
    }
    if (i % 8 == 7) {
      std::cout << "|" << std::endl;
    }
  }
  std::cout << " +--------+--------+" << std::endl;
}

#endif  // UTIL_HPP_
