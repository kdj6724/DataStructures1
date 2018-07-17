// StudentStackTest.cpp
// 2018-07-17
// kdj6724@gmail.com
#include "StudentStack.h"
int main() {
  StudentStack stack;
  Student student1(1, "1", "11");
  Student student2(2, "2", "22");
  Student student3(3, "3", "33");
  stack.Push(student1);
  stack.Push(student2);
  stack.Push(student3);
  stack.Display();
  stack.Pop();
  stack.Pop();
  stack.Display();
  return 0;
}
