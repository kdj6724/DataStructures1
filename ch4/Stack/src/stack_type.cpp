// stack_type.cpp
// 2018-07-20
// kdj6724@gmail.com
#include "stack_type.h"
StackType::StackType() {
  top_ = -1;
}
bool StackType::IsEmpty() const {
  return (top_ == -1);
}
bool StackType::IsFull() const {
  return (top_ == MAX_ITEMS - 1);
}
void StackType::Push(ItemType item) {
  if (IsFull())
    throw FullStack();
  items_[++top_] = item;
}
void StackType::Pop() {
  if (IsEmpty())
    throw EmptyStack();
  top_--;
}
ItemType StackType::Top() const {
  if (IsEmpty())
    throw EmptyStack();
  return items_[top_];
}
