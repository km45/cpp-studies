#include <type_traits>

//-----------------------------------------------------------------------------
// Utility
//-----------------------------------------------------------------------------
#define EXPECT_TRIVIAL(TYPE) \
  static_assert(std::is_trivial<TYPE>(), #TYPE " should be trivial.")

#define EXPECT_NON_TRIVIAL(TYPE) \
  static_assert(!std::is_trivial<TYPE>(), #TYPE " should be non-trivial.")

#define DEFAULT_CONSTRUCTOR(CLASS_NAME) CLASS_NAME()
#define DESTRUCTOR(CLASS_NAME) ~CLASS_NAME()
#define COPY_CONSTRUCTOR(CLASS_NAME) CLASS_NAME(CLASS_NAME&)
#define MOVE_CONSTRUCTOR(CLASS_NAME) CLASS_NAME(CLASS_NAME&&)
#define COPY_ASSIGNMENT_OPERATOR(CLASS_NAME) CLASS_NAME& operator=(CLASS_NAME&)
#define MOVE_ASSIGNMENT_OPERATOR(CLASS_NAME) CLASS_NAME& operator=(CLASS_NAME&&)

//-----------------------------------------------------------------------------
// Empty struct
//-----------------------------------------------------------------------------
struct Empty {};
EXPECT_TRIVIAL(Empty);

//-----------------------------------------------------------------------------
// Special member functions
//-----------------------------------------------------------------------------
struct ExplicitlyDefaultDefinedAllSpecialMemberFunctions {
#define CLASS_NAME ExplicitlyDefaultDefinedAllSpecialMemberFunctions
  DEFAULT_CONSTRUCTOR(CLASS_NAME) = default;
  DESTRUCTOR(CLASS_NAME) = default;
  COPY_CONSTRUCTOR(CLASS_NAME) = default;
  MOVE_CONSTRUCTOR(CLASS_NAME) = default;
  COPY_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
  MOVE_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
#undef CLASS_NAME
};

struct ExplicitlyDeleteDefinedAllSpecialMemberFunctions {
#define CLASS_NAME ExplicitlyDeleteDefinedAllSpecialMemberFunctions
  DEFAULT_CONSTRUCTOR(CLASS_NAME) = delete;
  DESTRUCTOR(CLASS_NAME) = delete;
  COPY_CONSTRUCTOR(CLASS_NAME) = delete;
  MOVE_CONSTRUCTOR(CLASS_NAME) = delete;
  COPY_ASSIGNMENT_OPERATOR(CLASS_NAME) = delete;
  MOVE_ASSIGNMENT_OPERATOR(CLASS_NAME) = delete;
#undef CLASS_NAME
};

struct
    ExplicitlyDefaultDefinedAllSpecialMemberFunctionsExceptDefaultConstructor {
#define CLASS_NAME \
  ExplicitlyDefaultDefinedAllSpecialMemberFunctionsExceptDefaultConstructor
  // DEFAULT_CONSTRUCTOR(CLASS_NAME)
  DESTRUCTOR(CLASS_NAME) = default;
  COPY_CONSTRUCTOR(CLASS_NAME) = default;
  MOVE_CONSTRUCTOR(CLASS_NAME) = default;
  COPY_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
  MOVE_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
#undef CLASS_NAME
};

struct UserDefinedSpecialMemberFunctions {
#define CLASS_NAME UserDefinedSpecialMemberFunctions
  DEFAULT_CONSTRUCTOR(CLASS_NAME) {}
  DESTRUCTOR(CLASS_NAME) = default;
  COPY_CONSTRUCTOR(CLASS_NAME) = default;
  MOVE_CONSTRUCTOR(CLASS_NAME) = default;
  COPY_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
  MOVE_ASSIGNMENT_OPERATOR(CLASS_NAME) = default;
#undef CLASS_NAME
};

EXPECT_TRIVIAL(ExplicitlyDefaultDefinedAllSpecialMemberFunctions);
EXPECT_TRIVIAL(ExplicitlyDeleteDefinedAllSpecialMemberFunctions);
EXPECT_NON_TRIVIAL(
    ExplicitlyDefaultDefinedAllSpecialMemberFunctionsExceptDefaultConstructor);
EXPECT_NON_TRIVIAL(UserDefinedSpecialMemberFunctions);
