#include <type_traits>

//-----------------------------------------------------------------------------
// Utility
//-----------------------------------------------------------------------------
#define EXPECT_STANDARD_LAYOUT(TYPE)             \
  static_assert(std::is_standard_layout<TYPE>(), \
                #TYPE " should be standard layout.")

#define EXPECT_NON_STANDARD_LAYOUT(TYPE)          \
  static_assert(!std::is_standard_layout<TYPE>(), \
                #TYPE " should be non-standard layout.")

//-----------------------------------------------------------------------------
// Prototype declaration
//-----------------------------------------------------------------------------
struct NonStaticReferenceAsMemberVariable;
struct EmptyStruct;
struct EmptyClass;
struct MemberVariable;
using NonStandardLayoutSample = NonStaticReferenceAsMemberVariable;
using StandardLayoutSample = EmptyStruct;
using StandardLayoutWithoutNonStaticMemberSample1 = EmptyStruct;
using StandardLayoutWithoutNonStaticMemberSample2 = EmptyClass;
using StandardLayoutWithNonStaticMemberSample1 = MemberVariable;
struct StandardLayoutWithNonStaticMemberSample2 {
  int x;
};
using StandardLayoutWithNonStaticPublicMemberSample = MemberVariable;

//-----------------------------------------------------------------------------
// Empty struct
//-----------------------------------------------------------------------------
struct EmptyStruct {};
class EmptyClass {};
EXPECT_STANDARD_LAYOUT(EmptyStruct);
EXPECT_STANDARD_LAYOUT(EmptyClass);

//-----------------------------------------------------------------------------
// Member variable
//-----------------------------------------------------------------------------

struct MemberVariable {
  int x1;   // non-static fundamental
  int* x2;  // non-static pointer
#if 0
  int& x3;                     // non-static reference
  NonStandardLayoutSample x4;  // non-static non-standard-layout
#endif
  StandardLayoutSample x5;  // non-static standard-layout

  static int y1;                      // static fundamental
  static int* y2;                     // static pointer
  static int& y3;                     // static reference
  static NonStandardLayoutSample y4;  // static non-standard-layout
  static StandardLayoutSample y5;     // static standard-layout
};

struct NonStaticReferenceAsMemberVariable {
  int& x3;  // non-static reference
};

struct NonStandardLayoutAsMemberVariable {
  NonStandardLayoutSample x4;  // non-static non-standard-layout
};

EXPECT_STANDARD_LAYOUT(MemberVariable);
EXPECT_NON_STANDARD_LAYOUT(NonStaticReferenceAsMemberVariable);
EXPECT_NON_STANDARD_LAYOUT(NonStandardLayoutAsMemberVariable);

//-----------------------------------------------------------------------------
// Member function
//-----------------------------------------------------------------------------
struct MemberFunction {
  void Func1() {}
  static void Func2() {}

#if 0
  virtual void Func3() {}
#endif

  int x;
  int& Func4() { return x; }
};

struct VirtualFunction {
  virtual void Func3() {}
};

EXPECT_STANDARD_LAYOUT(MemberFunction);
EXPECT_NON_STANDARD_LAYOUT(VirtualFunction);

//-----------------------------------------------------------------------------
// Single Inheritance
//-----------------------------------------------------------------------------
struct SingleNonVirtualInheritanceStandardLayout : StandardLayoutSample {};

struct SingleNonVirtualInheritanceNonStandardLayout : NonStandardLayoutSample {
};

struct SingleVirtualInheritanceStandardLayout : virtual StandardLayoutSample {};

struct SingleNonVirtualInheritanceFirstMemberIsNotDerived
    : StandardLayoutWithoutNonStaticMemberSample1 {
  int a;
  StandardLayoutWithoutNonStaticMemberSample1 x;
};

struct SingleNonVirtualInheritanceFirstMemberIsDerived
    : StandardLayoutWithoutNonStaticMemberSample1 {
  StandardLayoutWithoutNonStaticMemberSample1 x;
  int a;
};

struct
    SingleNonVirtualInheritanceVariableBasicClassDoesNotHaveVirtualMemberWhenMostDerivedClassHasNonVirtualMember
    : StandardLayoutWithoutNonStaticMemberSample1 {
  StandardLayoutWithNonStaticMemberSample2 x;
  int a;
};

struct
    SingleNonVirtualInheritanceVariableBasicClassHasNonVirtualMemberWhenMostDerivedClassHasNonVirtualMember
    : StandardLayoutWithNonStaticMemberSample1 {
  int a;
  StandardLayoutWithNonStaticMemberSample2 x;
};

EXPECT_STANDARD_LAYOUT(SingleNonVirtualInheritanceStandardLayout);
EXPECT_NON_STANDARD_LAYOUT(SingleNonVirtualInheritanceNonStandardLayout);
EXPECT_NON_STANDARD_LAYOUT(SingleVirtualInheritanceStandardLayout);

EXPECT_STANDARD_LAYOUT(SingleNonVirtualInheritanceFirstMemberIsNotDerived);
EXPECT_NON_STANDARD_LAYOUT(SingleNonVirtualInheritanceFirstMemberIsDerived);

EXPECT_STANDARD_LAYOUT(
    SingleNonVirtualInheritanceVariableBasicClassDoesNotHaveVirtualMemberWhenMostDerivedClassHasNonVirtualMember);
EXPECT_NON_STANDARD_LAYOUT(
    SingleNonVirtualInheritanceVariableBasicClassHasNonVirtualMemberWhenMostDerivedClassHasNonVirtualMember);

//-----------------------------------------------------------------------------
// Multiple Inheritance
//-----------------------------------------------------------------------------
struct MultipleInheritanceNonStaticMemberCount0
    : StandardLayoutWithoutNonStaticMemberSample1,
      StandardLayoutWithoutNonStaticMemberSample2 {};
struct MultipleInheritanceNonStaticMemberCount1
    : StandardLayoutWithoutNonStaticMemberSample1,
      StandardLayoutWithNonStaticMemberSample1 {};
struct MultipleInheritanceNonStaticMemberCount2
    : StandardLayoutWithNonStaticMemberSample1,
      StandardLayoutWithNonStaticMemberSample2 {};

EXPECT_STANDARD_LAYOUT(MultipleInheritanceNonStaticMemberCount0);
EXPECT_STANDARD_LAYOUT(MultipleInheritanceNonStaticMemberCount1);
EXPECT_NON_STANDARD_LAYOUT(MultipleInheritanceNonStaticMemberCount2);

//-----------------------------------------------------------------------------
// Access specifier
//-----------------------------------------------------------------------------
struct MemberAccessSpecifierForFunctions {
 public:
  void Hoge() {}

 protected:
  void Fuga();

 private:
  void Piyo();
};

struct SingleMemberAccessSpecifierPublicForVariable {
 public:
  int x;
};
struct SingleMemberAccessSpecifierProtectedForVariable {
 protected:
  int x;
};
struct SingleMemberAccessSpecifierPrivateForVariable {
 private:
  int x;
};

struct MultipleMemberAccessSpecifierForVariables {
 public:
  int x;

 private:
  int y;
};

EXPECT_STANDARD_LAYOUT(MemberAccessSpecifierForFunctions);
EXPECT_STANDARD_LAYOUT(SingleMemberAccessSpecifierPublicForVariable);
EXPECT_STANDARD_LAYOUT(SingleMemberAccessSpecifierProtectedForVariable);
EXPECT_STANDARD_LAYOUT(SingleMemberAccessSpecifierPrivateForVariable);
EXPECT_NON_STANDARD_LAYOUT(MultipleMemberAccessSpecifierForVariables);
