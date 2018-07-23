// queue_type.h
// 2018-07-23
// kdj6724@gmail.com
class FullQueue {
};
class EmptyQueue {
};

template <class ItemType>
struct NodeType {
  ItemType info;
  NodeType* next;
};

template <class ItemType>
class QueueType {
public:
  QueueType();
  virtual ~QueueType();
  void MakeEmpty();
  void Enqueue(ItemType item);
  void Dequeue(ItemType& item);
  bool IsEmpty() const;
  bool IsFull() const;
private:
  NodeType<ItemType>* front_;
  NodeType<ItemType>* rear_;
};

template <class ItemType>
QueueType<ItemType>::QueueType() {
  front_ = NULL;
  rear_ = NULL;
}
template <class ItemType>
QueueType<ItemType>::~QueueType() {
  MakeEmpty();
}
template <class ItemType>
void QueueType<ItemType>::MakeEmpty() {
  NodeType<ItemType>* tempNode;
  while (front_ != NULL) {
    tempNode = front_;
    front_ = front_->next;
    delete tempNode;
  }
}
template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType item) {
  NodeType<ItemType>* newNode;
  if (IsFull()) {
    throw FullQueue();
  } else {
    newNode = new NodeType<ItemType>;
    newNode->next = NULL;
    newNode->info = item;
    if (rear_ == NULL)
      front_ = newNode;
    else
      rear_->next = newNode;
    rear_ = newNode;
  }
}
template <class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item) {
  NodeType<ItemType>* tempPtr;
  if (IsEmpty()) {
    throw EmptyQueue();
  } else {
    tempPtr = front_;
    item = tempPtr->info;
    front_ = tempPtr->next;
    delete tempPtr;
  }
}
template <class ItemType>
bool QueueType<ItemType>::IsEmpty() const {
  return (front_ == NULL);
}
template <class ItemType>
bool QueueType<ItemType>::IsFull() const {
  NodeType<ItemType>* tmpNode;
  try {
    tmpNode = new NodeType<ItemType>;
    delete tmpNode;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

