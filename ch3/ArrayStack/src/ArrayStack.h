// Stack.h
// 2018-07-17
// kdj6724@gmail.com

#ifndef CH3_ARRAYSTACK_H_
#define CH3_ARRAYSTACK_H_
#include <cstdio>
#include <cstdlib>
#define MAX_STACK_SIZE 80
class ArrayStack {
private:
  int top_;
  int data_[MAX_STACK_SIZE];
public:
  ArrayStack();
  bool IsEmpty();
  bool IsFull();
  void Push(int val);
  int Pop();
  int Peek();
  void Display();
};
#endif  // CH3_ARRAYSTACK_H_
