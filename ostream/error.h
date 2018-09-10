#include <iostream>

enum class Error : int {
  kOk,
  kInvalidInput,
  kInternalError,
  kMissingDataError,
  kUnexpectedError
};

template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const Error e) {
  os << static_cast<int>(e);
  return os;
}
