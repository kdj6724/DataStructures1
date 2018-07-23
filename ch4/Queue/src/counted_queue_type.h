// queue_type.h
// 2018-07-21
// kdj6724@gmail.com
#ifndef COUNTED_QUEUE_TYPE_H_
#define COUNTED_QUEUE_TYPE_H_
#include "queue_type.h"
template <class ItemType>
class CountedQueueType : public QueueType<ItemType> {
public:
  CountedQueueType(int max);
  void Enqueue(ItemType item);
  void Dequeue(ItemType& item);
  int LengthIs() const;
private:
  int length_;
};

template <class ItemType>
CountedQueueType<ItemType>::CountedQueueType(int max) 
    : QueueType<ItemType>(max) {
  length_ = 0;
}
template <class ItemType>
void CountedQueueType<ItemType>::Enqueue(ItemType item) {
  try {
    QueueType<ItemType>::Enqueue(item);
    length_++;
  } catch(FullQueue) {
    throw FullQueue();
  }
}
template <class ItemType>
void CountedQueueType<ItemType>::Dequeue(ItemType& item) {
  try {
    QueueType<ItemType>::Dequeue(item);
    length_--;
  } catch(EmptyQueue) {
    throw EmptyQueue();
  }
}
template <class ItemType>
int CountedQueueType<ItemType>::LengthIs() const {
  return length_;
}
#endif // COUNTED_QUEUE_TYPE_H_
