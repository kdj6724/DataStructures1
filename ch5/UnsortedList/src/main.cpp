// unsorted_type.h
// 2018-07-25
// kdj6724@gmail.com
#include <iostream>
#include <string>
#include <memory>
#include "unsorted_list.h"
int main() {
  std::unique_ptr<UnsortedType<std::string>> nameList;
  nameList.reset(new UnsortedType<std::string>);
  std::string name;
  std::string findName = "kdj";
  std::cin >> name;
  nameList->ResetList();
  while (name.at(0) != 'q') {
    nameList->InsertItem(name);
    std::cin >> name;
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

  return 0;
}
