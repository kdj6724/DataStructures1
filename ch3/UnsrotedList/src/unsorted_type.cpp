// unsorted_type.cpp
// 2018-07-19
// kdj6724@gmail.com
#include "unsorted_type.h"
UnsortedType::UnsortedType() {
  length_ = 0;
}
bool UnsortedType::IsFull() const {
  return (length_ == MAX_ITEMS);
}
int UnsortedType::LengthIs() const {
  return length_;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) {
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length_);
  while (moreToSearch && !found) {
    switch (item.ComparedTo(info_[location])) {
      case ItemType::LESS:
        break;
      case ItemType::GREATER:
        location++;
        moreToSearch = (location < length_);
        break;
      case ItemType::EQUAL:
        found = true;
        item = info_[location];
        break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item) {
  info_[length_] = item;
  length_++;
}
void UnsortedType::DeleteItem(ItemType item) {
  int location = 0;
  while (item.ComparedTo(info_[location]) != ItemType::EQUAL)
    location++;
  info_[location] = info_[length_ - 1];
  length_--;
}
void UnsortedType::ResetList() {
  currentPos_ = -1;
}
void UnsortedType::GetNextItem(ItemType& item) {
  item = info_[++currentPos_];
}
