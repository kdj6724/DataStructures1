// main.cpp
#include <iostream>
#include "sorted_type.h"
#include "item_type.h"

void GetData(std::ifstream& dataFile, ItemType& item) {
  char inputString[16] = {0,};
  dataFile.getline(inputString, 16);
  item.Initialize(atoi(inputString));
  printf("%s \n", inputString);
}
void PrintList(std::ofstream& dataFile, SortedType list) {
  int length;
  ItemType item;
  list.ResetList();
  length = list.LengthIs();
  for (int i=1; i<=length; i++) {
    list.GetNextItem(item);
    item.Print(dataFile);
  }
}
void CreateListFromFile(std::ifstream& dataFile, SortedType& list) {
  ItemType item;
  //list.MakeEmpty();
  GetData(dataFile, item);
  while(dataFile) {
    if (!list.IsFull())
      list.InsertItem(item);
    GetData(dataFile, item);
  }
}
void usage(void) {
  printf(" - ./unsorted <input> <output>\n");
}
int main(int argc, char** argv) {
  if (argc < 3) {
    usage();
  }
  SortedType list;
  std::ifstream inputFile(argv[1]);
  CreateListFromFile(inputFile, list);
  inputFile.close();

  std::ofstream outFile(argv[2]);
  PrintList(outFile, list);
  outFile.close();
}

