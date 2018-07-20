// sorted_type.cpp
// 2018-07-20
// kdj6724@gmail.com
#include "sorted_type.h"
SortedType::SortedType() {
  length_ = 0;
}
bool SortedType::IsFull() const {
  return (length_ == MAX_ITEMS);
}
int SortedType::LengthIs() const {
  return length_;
}
#if 1
void SortedType::RetrieveItem(ItemType& item, bool& found) {
  bool moreToSearch;
  int first = 0;
  int last = length_ - 1;
  int midPoint = length_/2;
  found = false;
  moreToSearch = (first <= last);
  while(moreToSearch && !found) {
    midPoint = (first+last)/2;
    switch(item.ComparedTo(info_[midPoint])) {
      case ItemType::LESS:
        last = midPoint - 1;
        break;
      case ItemType::GREATER:
        first = midPoint + 1;
        break;
      case ItemType::EQUAL:
        found = true;
        item = info_[midPoint];
        break;
    }
  }
}
#else
void SortedType::RetrieveItem(ItemType& item, bool& found) {
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
#endif
void SortedType::InsertItem(ItemType item) {
  bool moreToSearch;
  int location = 0;
  moreToSearch = (location < length_);
  while (moreToSearch) {
    switch (item.ComparedTo(info_[location])) {
      case ItemType::LESS:
        moreToSearch = false;
        break;
      case ItemType::GREATER:
        location++;
        moreToSearch = (location < length_);
        break;
    }
  }
  for (int i=length_; i>location; i--)
    info_[i] = info_[i - 1];
  info_[location] = item;
  length_++;
}
void SortedType::DeleteItem(ItemType item) {
  int location = 0;
  while (item.ComparedTo(info_[location]) != ItemType::EQUAL)
    location++;
  for (int i=location + 1; i<length_; i++)
    info_[i - 1] = info_[i];
  length_--;
}
void SortedType::ResetList() {
  currentPos_ = -1;
}
void SortedType::GetNextItem(ItemType& item) {
  item = info_[++currentPos_];
}
