// main.h
// 2018-07-25
// kdj6724@gmail.com
#include <iostream>
#include <string>
#include <memory>
#include "circular_list.h"
int main() {
  std::unique_ptr<CircularType<std::string>> nameList;
  nameList.reset(new CircularType<std::string>);
  std::string name;
  std::string findName = "kdj";
  std::cin >> name;
  nameList->ResetList();
  while (name.at(0) != 'q') {
    nameList->InsertItem(name);
    std::cin >> name;
  }

  int len = nameList->LengthIs();
  std::cout << "len : " << len << std::endl;
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
