// stack_type.cpp
// 2018-07-23
// kdj6724@gmail.com
#include <iostream>
#include "stack_type.h"

StackType::StackType() {
  topPtr_ = NULL;
}
StackType::~StackType() {
  NodeType* tempPtr;

  if (topPtr_ == NULL)
    return;

  while(tempPtr != NULL) {
    tempPtr = topPtr_;
    topPtr_ = topPtr_->next;
    delete tempPtr;
  }
}
bool StackType::IsEmpty() const {
  return (topPtr_ == NULL);
}
bool StackType::IsFull() const {
  NodeType* location;
  try {
    location = new NodeType;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}
void StackType::Push(ItemType item) {
  if (IsFull()) {
    throw FullStack();
  } else {
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = topPtr_;
    topPtr_ = location;
  }
}
void StackType::Pop() {
  if (IsEmpty()) {
    throw EmptyStack();
  } else {
    NodeType* tempPtr;
    tempPtr = topPtr_;
    topPtr_ = topPtr_->next;
    delete tempPtr;
  }
}
ItemType StackType::Top() const {
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr_->info;
}

