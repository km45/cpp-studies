#include <csignal>
#include <iostream>

void SignaleHandler(int signal) {
  std::cout << "SignaleHandler() is called. (signal = " << signal << " )"
            << std::endl;

  std::signal(signal, SIG_DFL);  // restore to default handler
  std::raise(signal);            // call default handler
}

void sigterm() {
  std::signal(SIGTERM, SignaleHandler);

  std::cout << "Kill process by kill command. Waiting..." << std::endl;
  while (true) {
    // Wait
  }
}

void sigsegv() {
  std::signal(SIGSEGV, SignaleHandler);

  int* x = nullptr;
  std::cout << *x << std::endl;  // null pointer exception
}

void sigint() {
  std::signal(SIGINT, SignaleHandler);

  std::cout << "Terminate program by Ctrl+C. Waiting..." << std::endl;
  while (true) {
    // Wait
  }
}

void sigill() {
  std::signal(SIGILL, SignaleHandler);

  // https://codegolf.stackexchange.com/a/100646
  asm("ud2");
}

void sigabrt() {
  std::signal(SIGABRT, SignaleHandler);

  std::terminate();  // Call std::abort()
}

void sigfpe() {
  std::signal(SIGFPE, SignaleHandler);

  int x = 2;
  int y = 0;
  auto z = x / y;  // Divided by zero
  std::cout << z << std::endl;
}

int main() {
  std::cout << "1: SIGTERM" << std::endl;
  std::cout << "2: SIGSEGV" << std::endl;
  std::cout << "3: SIGINT" << std::endl;
  std::cout << "4: SIGILL" << std::endl;
  std::cout << "5: SIGABRT" << std::endl;
  std::cout << "6: SIGFPE" << std::endl;

  std::cout << std::endl;

  std::cout << "Select by number: ";

  int x = 0;
  std::cin >> x;

  std::cout << std::endl;

  switch (x) {
    case 1:
      sigterm();
      break;
    case 2:
      sigsegv();
      break;
    case 3:
      sigint();
      break;
    case 4:
      sigill();
      break;
    case 5:
      sigabrt();
      break;
    case 6:
      sigfpe();
      break;
  }

  return 0;
}
