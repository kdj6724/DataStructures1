// StudentStack.h
// 2018-07-17
// kdj6724@gmail.com

#ifndef CH3_STUDENTSTACK_H_
#define CH3_STUDENTSTACK_H_
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_STRING 100
#define MAX_STACK_SIZE 100
class Student {
private:
  int id_;
  char name_[MAX_STRING];
  char dept_[MAX_STRING];
public:
  Student(int i=0, char* n="", char* d="");
  void Set(int i, char* n, char* d);
  void Display();
};
class StudentStack {
private:
  int top_;
  Student data_[MAX_STACK_SIZE];
public:
  StudentStack();
  void Push(Student data);
  Student Pop();
  Student Peek();
  bool IsEmpty();
  bool IsFull();
  void Display();
};
#endif  // CH3_STUDENTSTACK_H_
