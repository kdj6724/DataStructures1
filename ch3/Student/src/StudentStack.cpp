// StudentStack.cpp
// 2018-07-17
// kdj6724@gmail.com
#include "StudentStack.h"
inline void error(char* str) {
  printf("%s\n", str);
  exit(1);
}
Student::Student(int i, char* n, char* d) {
  Set(i, n, d);
}
void Student::Set(int i, char* n, char* d) {
  id_ = i;
  strcpy(name_, n);
  strcpy(dept_, d);
}
void Student::Display() {
  printf("id:%-15d name:%-10s dept:%-20s\n", id_, name_, dept_);
}

StudentStack::StudentStack() {
  top_ = -1;
}
void StudentStack::Push(Student data) {
  if (IsFull())
    error("stack is full");
  data_[++top_] = data;
}
Student StudentStack::Pop() {
  if (IsEmpty())
    error("stack is empty");
  return data_[top_--];
}
Student StudentStack::Peek() {
  if (IsEmpty())
    error("stack is empty");
  return data_[top_];
}
bool StudentStack::IsEmpty() {
  return top_ == -1;
}
bool StudentStack::IsFull() {
  return top_ == (MAX_STACK_SIZE + 1);
}
void StudentStack::Display() {
  printf("Total Students %d\n", top_+1);
  for (int i=0; i<top_+1; i++)
    data_[i].Display();
  printf("\n");
}
