// main.cpp
// 2018-07-21
// kdj6724@gmail.com
#include <iostream>
#include "stack_type.h"
#include "counted_queue_type.h"

int main() {
  bool palindrome = true;
  char character;
  StackType<char> stack(40);
  CountedQueueType<char> queue(40);
  char stackChar;
  char queChar;
  std::cout << "Enter a string; press return." << std::endl;
  std::cin.get(character);
  while (character != '\n') {
    stack.Push(character);
    queue.Enqueue(character);
    std::cin.get(character);
  }
  std::cout << "Queue length : " << queue.LengthIs() << std::endl;
  while (palindrome && !queue.IsEmpty()) {
    stackChar = stack.Top();
    stack.Pop();
    queue.Dequeue(queChar);
    if (stackChar != queChar)
      palindrome = false;
  }
  if (palindrome)
    std::cout << "String is a palindrome" << std::endl;
  else
    std::cout << "String is not a palindrome" << std::endl;
}
