// stack_type.cpp
// 2018-07-20
// kdj6724@gmail.com
#include "stack_type.h"
template<class ItemType>
StackType<ItemType>::StackType() {
  top_ = -1;
}
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
  return (top_ == -1);
}
template<class ItemType>
bool StackType<ItemType>::IsFull() const {
  return (top_ == MAX_ITEMS - 1);
}
template<class ItemType>
void StackType<ItemType>::Push(ItemType item) {
  if (IsFull())
    throw FullStack();
  items_[++top_] = item;
}
template<class ItemType>
void StackType<ItemType>::Pop() {
  if (IsEmpty())
    throw EmptyStack();
  top_--;
}
template<class ItemType>
ItemType StackType<ItemType>::Top() const {
  if (IsEmpty())
    throw EmptyStack();
  return items_[top_];
}
