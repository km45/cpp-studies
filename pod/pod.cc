#include <array>
#include <type_traits>
#include <vector>

//-----------------------------------------------------------------------------
// Utility
//-----------------------------------------------------------------------------
#define EXPECT_POD(...) \
  static_assert(std::is_pod<__VA_ARGS__>::value, #__VA_ARGS__ " should be POD.")

#define EXPECT_NON_POD(...) \
  static_assert(!std::is_pod<__VA_ARGS__>::value, #__VA_ARGS__ " should be non-POD.")

#define EXPECT_TRIVIAL(TYPE) \
  static_assert(std::is_trivial<TYPE>(), #TYPE " should be trivial.")

#define EXPECT_NON_TRIVIAL(TYPE) \
  static_assert(!std::is_trivial<TYPE>(), #TYPE " should be non-trivial.")

#define EXPECT_STANDARD_LAYOUT(TYPE)             \
  static_assert(std::is_standard_layout<TYPE>(), \
                #TYPE " should be standard layout.")

#define EXPECT_NON_STANDARD_LAYOUT(TYPE)          \
  static_assert(!std::is_standard_layout<TYPE>(), \
                #TYPE " should be non-standard layout.")

//-----------------------------------------------------------------------------
// POD
//-----------------------------------------------------------------------------
struct Empty {};
EXPECT_POD(Empty);

struct NonStandardLayout {
  int& x;  // non-static reference
};
EXPECT_NON_POD(NonStandardLayout);

struct NonTrivial {
  NonTrivial(const NonTrivial&) = default;
};
EXPECT_NON_POD(NonTrivial);

EXPECT_POD(int[]);
EXPECT_POD(std::array<int, 2>);

struct RawArray {
  int x[2];
};
struct StdArray {
  std::array<int, 2> x;
};
EXPECT_POD(RawArray);
EXPECT_POD(StdArray);

struct Vector {
  std::vector<int> x;
};
EXPECT_NON_POD(Vector);
EXPECT_STANDARD_LAYOUT(Vector);
EXPECT_NON_TRIVIAL(Vector);
