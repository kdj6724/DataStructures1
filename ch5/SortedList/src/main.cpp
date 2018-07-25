// unsorted_type.h
// 2018-07-25
// kdj6724@gmail.com
#include <iostream>
#include <string>
#include <memory>
#include "sorted_list.h"
int main() {
  std::unique_ptr<SortedType<char>> nameList;
  nameList.reset(new SortedType<char>);
  char name;
  char findName = 'q';
  std::cin.get(name);
  nameList->ResetList();
  while (name != '\n') {
    nameList->InsertItem(name);
    std::cin.get(name);
  }

  int len = nameList->LengthIs();
  while (len > 0) {
    nameList->GetNextItem(name);
    std::cout << "name : " << name << std::endl;
    len--;
  }
  bool res = false;
  nameList->RetrieveItem(findName, res);
  std::cout << "res : " << res << std::endl;

  nameList->DeleteItem(findName);
  nameList->RetrieveItem(findName, res);
  std::cout << "res : " << res << std::endl;

  len = nameList->LengthIs();
  nameList->ResetList();
  while (len > 0) {
    nameList->GetNextItem(name);
    std::cout << "name : " << name << std::endl;
    len--;
  }
  return 0;
}
