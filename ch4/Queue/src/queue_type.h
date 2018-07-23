// queue_type.h
// 2018-07-21
// kdj6724@gmail.com

class FullQueue {
};
class EmptyQueue {
};
template <class ItemType>
class QueueType {
public:
  QueueType(int max);
  QueueType();
  virtual ~QueueType();
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  void Enqueue(ItemType item);
  void Dequeue(ItemType& item);
protected:
  int front_;
  int rear_;
  ItemType* items_;
  int maxQueue_;
};

template <class ItemType>
QueueType<ItemType>::QueueType(int max) {
  maxQueue_ = max + 1;
  front_ = maxQueue_ - 1;
  rear_ = maxQueue_ - 1;
  items_ = new ItemType[maxQueue_];

  items_ = new ItemType[maxQueue_];
}
template <class ItemType>
QueueType<ItemType>::QueueType() {
  maxQueue_ = 30 + 1;
  front_ = maxQueue_ - 1;
  rear_ = maxQueue_ - 1;
  items_ = new ItemType[maxQueue_];
}
template <class ItemType>
QueueType<ItemType>::~QueueType() {
  delete [] items_;
}
template <class ItemType>
void QueueType<ItemType>::MakeEmpty() {
  front_ = maxQueue_ - 1;
  rear_ = maxQueue_ - 1;
}
template <class ItemType>
bool QueueType<ItemType>::IsEmpty() const {
  return (rear_ == front_);
}
template <class ItemType>
bool QueueType<ItemType>::IsFull() const {
  return ((rear_ + 1) % maxQueue_ == front_);
}
template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType item) {
  if (IsFull()) {
    throw FullQueue();
  } else {
    rear_ = (rear_ + 1) % maxQueue_;
    items_[rear_] = item;
  }
}
template <class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item) {
  if (IsEmpty()) {
    throw EmptyQueue();
  } else {
    front_ = (front_ + 1) % maxQueue_;
    item = items_[front_];
  }
}

