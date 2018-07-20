// main.cpp
// 2018-07-20
// kdj6724@gmail.com

#include <iostream>
#include "stack_type.h"
bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);

int main() {
  ItemType item;
  char symbol;
  StackType stack;
  bool balanced = true;
  char openSymbol;

  std::cout << "Enter an expression and press return." << std::endl;
  std::cin.get(symbol);
  while (symbol != '\n' && balanced) {
    if (IsOpen(symbol)) {
      item.Initialize(symbol);
      stack.Push(item);
    } else if (IsClosed(symbol)) {
      if (stack.IsEmpty()) {
        balanced = false;
      } else {
        item = stack.Top();
        openSymbol = item.value_;
        stack.Pop();
        balanced = Matches(symbol, openSymbol);
      }
    }
    std::cin.get(symbol);
  }
  if (balanced == true)
    std::cout << "Expression is well formed." << std::endl;
  else
    std::cout << "Expression is bad formed." << std::endl;

  return 0;
}

bool IsOpen(char symbol) {
  if (symbol == '[' || symbol == '{' || symbol == '(')
    return true;
  else
    return false;
}

bool IsClosed(char symbol) {
  if (symbol == ']' || symbol == '}' || symbol == ')')
    return true;
  else
    return false;
}

bool Matches(char symbol, char openSymbol) {
  bool res = false;
  if (openSymbol == '[' && symbol == ']')
    res = true;
  else if (openSymbol == '{' && symbol == '}')
    res = true;
  else if (openSymbol == '(' && symbol == ')')
    res = true;

  return res;
}
