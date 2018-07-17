// ArrayStackTest.cpp
// 2018-07-17
// kdj6724@gmail.com
#include "ArrayStack.h"

int main() {
  ArrayStack stack;
  for (int i=0; i<10; i++)
    stack.Push(i);
  stack.Display();
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Display();
  return 0;
}
