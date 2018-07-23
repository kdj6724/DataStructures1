// main.cpp
// 2018-07-23
// kdj6724@gmail.com
#include <iostream>
#include "stack_type.h"

int main() {
  char character;
  bool stackEmpty;
  StackType stack;
  std::cin.get(character);
  while (character != '\n') {
    stack.Push(character);
    std::cin.get(character);
  }
 
  stackEmpty = stack.IsEmpty();
  while(stackEmpty == false) {
    if (stack.IsEmpty()) {
      stackEmpty = true;
    } else {
      std::cout << "value : " << stack.Top() << std::endl;
      stack.Pop();
    }
  }
  return 0;
}
