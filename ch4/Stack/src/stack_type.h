// stack_type.h
// 2018-07-20
// kdj6724@gmail.com
#ifndef CH4_STACK_TYPE_H_
#define CH4_STACK_TYPE_H_
#include "item_type.h"
#define MAX_ITEMS 100
class FullStack {
};
class EmptyStack {
};
class StackType {
public:
  StackType();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(ItemType item);
  void Pop();
  ItemType Top() const;
private:
  int top_;
  ItemType items_[MAX_ITEMS];
};
#endif  // CH4_STACK_TYPE_H_
