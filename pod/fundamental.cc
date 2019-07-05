// Refer: https://ja.cppreference.com/w/cpp/language/types

#include <cstdint>
#include <type_traits>

#define ASSERT_FUNDAMENTAL(TYPE)             \
  static_assert(std::is_fundamental<TYPE>(), \
                #TYPE " is expected to be fundamental but not.")

ASSERT_FUNDAMENTAL(void);

// NOTE: `std::nullptr_t` is not a pointer type.
ASSERT_FUNDAMENTAL(std::nullptr_t);

// NOTE: `sizeof(bool) != 1` is allowed.
ASSERT_FUNDAMENTAL(bool);

ASSERT_FUNDAMENTAL(short);  // NOLINT
ASSERT_FUNDAMENTAL(int);
ASSERT_FUNDAMENTAL(long);            // NOLINT
ASSERT_FUNDAMENTAL(long long);       // NOLINT
ASSERT_FUNDAMENTAL(unsigned short);  // NOLINT
ASSERT_FUNDAMENTAL(unsigned int);
ASSERT_FUNDAMENTAL(unsigned long);       // NOLINT
ASSERT_FUNDAMENTAL(unsigned long long);  // NOLINT

ASSERT_FUNDAMENTAL(std::size_t);

// NOTE: These types are optional.
ASSERT_FUNDAMENTAL(std::int8_t);
ASSERT_FUNDAMENTAL(std::int16_t);
ASSERT_FUNDAMENTAL(std::int32_t);
ASSERT_FUNDAMENTAL(std::int64_t);
ASSERT_FUNDAMENTAL(std::uint8_t);
ASSERT_FUNDAMENTAL(std::uint16_t);
ASSERT_FUNDAMENTAL(std::uint32_t);
ASSERT_FUNDAMENTAL(std::uint64_t);

// NOTE: These types are required.
ASSERT_FUNDAMENTAL(std::int_fast8_t);
ASSERT_FUNDAMENTAL(std::int_fast16_t);
ASSERT_FUNDAMENTAL(std::int_fast32_t);
ASSERT_FUNDAMENTAL(std::int_fast64_t);
ASSERT_FUNDAMENTAL(std::uint_fast8_t);
ASSERT_FUNDAMENTAL(std::uint_fast16_t);
ASSERT_FUNDAMENTAL(std::uint_fast32_t);
ASSERT_FUNDAMENTAL(std::uint_fast64_t);

// NOTE: These types are required.
ASSERT_FUNDAMENTAL(std::int_least8_t);
ASSERT_FUNDAMENTAL(std::int_least16_t);
ASSERT_FUNDAMENTAL(std::int_least32_t);
ASSERT_FUNDAMENTAL(std::int_least64_t);
ASSERT_FUNDAMENTAL(std::uint_least8_t);
ASSERT_FUNDAMENTAL(std::uint_least16_t);
ASSERT_FUNDAMENTAL(std::uint_least32_t);
ASSERT_FUNDAMENTAL(std::uint_least64_t);

// NOTE: These types are required.
ASSERT_FUNDAMENTAL(std::intmax_t);
ASSERT_FUNDAMENTAL(std::uintmax_t);

// NOTE: These types are optional.
ASSERT_FUNDAMENTAL(std::intptr_t);
ASSERT_FUNDAMENTAL(std::uintptr_t);

// NOTE: "char" is different from "signed char".
//   The alignment and representation of "char" is same as
//   either "signed char" or "unsigned char".
//   Treated these 3 types as different type.
//
// NOTE: Can treat any UTF-8 bit code >= C++14. Not <= C++11.
ASSERT_FUNDAMENTAL(char);
ASSERT_FUNDAMENTAL(signed char);
ASSERT_FUNDAMENTAL(unsigned char);

// NOTE: `char8_t` >= C++20
ASSERT_FUNDAMENTAL(char16_t);
ASSERT_FUNDAMENTAL(char32_t);

ASSERT_FUNDAMENTAL(float);
ASSERT_FUNDAMENTAL(double);
ASSERT_FUNDAMENTAL(long double);

// NOTE: C++ standard for numeric limits are changed in C++20.
//   - Allowed any representation such that one's complement <= C++17
//   - Allowed only two's complement >= C++20
