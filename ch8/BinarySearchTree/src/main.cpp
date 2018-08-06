// main.cpp
// 2018-08-06
// kdj6724@gmail.com
#include <fstream>
#include <memory>
#include "binary_search_tree.h"

int main() {
  std::unique_ptr<TreeType<char>> tree(new TreeType<char>);
  char character;
  std::cin.get(character);
  while (character != '\n') {
    tree->InsertItem(character);
    std::cin.get(character);
  }
  std::ofstream ofs;
  ofs.open ("./test.txt", std::ofstream::out | std::ofstream::app);
  tree->Print(ofs);
  ofs.close();
  return 0;
}
