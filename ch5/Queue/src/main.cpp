// main.cpp
// 2018-07-23
// kdj6724@gmail.com
#include <iostream>
#include "queue_type.h"

int main() {
  QueueType<char> queue;
  char character; 

  std::cin.get(character);
  while(character != '\n') {
    queue.Enqueue(character);
    std::cin.get(character);
  }

  while(queue.IsEmpty() == false) {
    queue.Dequeue(character);
    std::cout << "out : " << character << std::endl;
  }
  return 0;
}
