// unsorted_type.h
// 2018-07-19
// kdj6724@gmail.com
#ifndef CH3_UNSORTED_TYPE_H_
#define CH3_UNSORTED_TYPE_H_
#include "item_type.h"
#define MAX_ITEMS 100
class UnsortedType {
public:
  UnsortedType();
  bool IsFull() const;
  int LengthIs() const;
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
private:
  int length_;
  ItemType info_[MAX_ITEMS];
  int currentPos_;
};
#endif // CH3_UNSORTED_TYPE_H_
