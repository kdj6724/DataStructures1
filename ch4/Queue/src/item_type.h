// item_type.h
// 2018-07-19
// kdj6724@gmail.com
#ifndef CH3_ITEM_TYPE_H_
#define CH3_ITEM_TYPE_H_
#include <fstream>

class ItemType {
public:
  int value_;
  enum RelationType {
    LESS = 0,
    GREATER,
    EQUAL
  };
  ItemType() { value_ = 0; }
  RelationType ComparedTo(ItemType item) const {
    if (value_ < item.value_)
      return LESS;
    else if (value_ > item.value_)
      return GREATER;
    else
      return EQUAL;
  }
  void Print(std::ofstream& stream) const { stream << value_ << " "; }
  void Initialize(int number) { value_ = number; }
};
#endif // CH3_ITEM_TYPE_H_

