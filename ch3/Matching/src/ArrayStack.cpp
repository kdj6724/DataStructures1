// ArrayStack.cpp
// 2018-07-17
// kdj6724@gmail.com
#include "ArrayStack.h"
inline void error(char* message) {
  printf("%s\n", message);
  exit(1);
}
ArrayStack::ArrayStack() {
  top_ = -1;
}
bool ArrayStack::IsEmpty() {
    return top_==-1;
}
bool ArrayStack::IsFull() {
  return top_ == (MAX_STACK_SIZE - 1);
}
void ArrayStack::Push(int val) {
  if (IsFull()) 
    error("stack is full");
  data_[++top_] = val;
}
int ArrayStack::Pop() {
  if (IsEmpty())
    error("stack is empty");
  return data_[top_--];
}
int ArrayStack::Peek() {
  if (IsEmpty())
    error("stack is empty");
  return data_[top_];
}
void ArrayStack::Display() {
  printf("Total count %d\n", top_ + 1);
  for (int i=0; i<top_+1; i++) 
    printf("<%2d> ", data_[i]);
  printf("\n");
}
