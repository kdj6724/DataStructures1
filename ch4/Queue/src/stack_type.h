// stack_type.h
// 2018-07-20
// kdj6724@gmail.com
#ifndef CH4_STACK_TYPE_H_
#define CH4_STACK_TYPE_H_
#include "item_type.h"
class FullStack {
};
class EmptyStack {
};
template<class ItemType>
class StackType {
public:
  StackType(int max);
  StackType();
  virtual ~StackType();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(ItemType item);
  void Pop();
  ItemType Top() const;
private:
  int top_;
  ItemType* items_;
  int maxStack_;
};

template<class ItemType>
StackType<ItemType>::StackType(int max) {
  top_ = -1;
  maxStack_ = max;
  items_ = new ItemType[maxStack_];
}
template<class ItemType>
StackType<ItemType>::StackType() {
  top_ = -1;
  maxStack_ = 500;
  items_ = new ItemType[maxStack_];
}
template<class ItemType>
StackType<ItemType>::~StackType() {
  delete [] items_;
}
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
  return (top_ == -1);
}
template<class ItemType>
bool StackType<ItemType>::IsFull() const {
  return (top_ == maxStack_ - 1);
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
#endif  // CH4_STACK_TYPE_H_
