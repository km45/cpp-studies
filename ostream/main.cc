#include <iostream>

#include "error.h"
#include "point.h"
#include "savedata.h"

int main() {
  Point point(1, 2);
  std::cout << point << std::endl;

  Error error = Error::kUnexpectedError;
  std::cout << error << std::endl;

  SaveData data;
  data.content.level = 5;
  data.content.hp = 125;
  data.content.mp = 96;
  data.content.flags[1] = true;
  std::cout << data << std::endl;

  return 0;
}
