// `throw` and `throw e` are different.
// `throw e` makes copy object of `e` and throw it.
// `throw` does not make copy object and rethrow `e`.

#include <iostream>

#define LOG(_MESSAGE)                                      \
  {                                                        \
    std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" \
              << " "                                       \
              << "[this=" << this << "]"                   \
              << " " << (_MESSAGE) << std::endl;           \
  }

class TestException {
 public:
  TestException() { LOG("DefaultConstructor"); }

  /* implicit */ TestException(const TestException& e) {
    LOG("CopyConstructor");
  }

  virtual ~TestException() { LOG("Destructor"); }
};

#undef LOG

void Test1() {
  try {
    try {
      throw TestException();
    } catch (const TestException& e) {
      throw;
    }
  } catch (const TestException&) {
  }
}

void Test2() {
  try {
    try {
      throw TestException();
    } catch (const TestException& e) {
      throw e;
    }
  } catch (const TestException&) {
  }
}

void Test3() {
  try {
    try {
      throw TestException();
    } catch (const TestException&) {
      std::rethrow_exception(std::current_exception());
    }
  } catch (const TestException&) {
  }
}

void Test4() {
  try {
    try {
      throw TestException();
    } catch (const TestException& e) {
      std::rethrow_exception(std::make_exception_ptr(e));
    }
  } catch (const TestException&) {
  }
}

#define RUN(_FUNCTION_NAME)                                                   \
  {                                                                           \
    std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << #_FUNCTION_NAME \
              << std::endl;                                                   \
    _FUNCTION_NAME();                                                         \
  }

int main() {
  RUN(Test1);
  RUN(Test2);
  RUN(Test3);
  RUN(Test4);
  return 0;
}

#undef RUN
