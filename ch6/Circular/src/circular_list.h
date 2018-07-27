// circular_list.h
// 2018-07-24
// kdj6724@gmail.com
#ifndef CH6_CIRCULAR_LIST_H_
#define CH6_CIRCULAR_LIST_H_
template <class ItemType>
struct NodeType {
  ItemType info;
  NodeType* next;
};

template <class ItemType>
class CircularType {
public:
  CircularType();
  virtual ~CircularType();
  bool IsFull() const;
  bool IsEmpty() const;
  int LengthIs() const;
  void MakeEmpty();
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
  void FindItem(NodeType<ItemType>* listData, ItemType item,
      NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc,
      bool& found);
private:
  NodeType<ItemType>* listData_;
  int length_;
  NodeType<ItemType>* currentPos_;
};

template <class ItemType>
CircularType<ItemType>::CircularType() {
  length_ = 0;
  listData_ = NULL;
}

template <class ItemType>
CircularType<ItemType>::~CircularType() {
  MakeEmpty();
}

template <class ItemType>
bool CircularType<ItemType>::IsFull() const {
  NodeType<ItemType>* location;
  try {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}
template <class ItemType>
bool CircularType<ItemType>::IsEmpty() const {
  return (listData_ == NULL);
}

template <class ItemType>
int CircularType<ItemType>::LengthIs() const {
  return length_;
}

template <class ItemType>
void CircularType<ItemType>::MakeEmpty() {
  NodeType<ItemType>* tempPtr;
  // 마지막 node를 지울때 문제가 있어서 이렇게 함
  int len = LengthIs(); 
  while (len) {
    tempPtr = listData_;
    listData_ = listData_->next;
    delete tempPtr;
    len--;
  }
  length_ = 0;
}

template <class ItemType>
void CircularType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
  NodeType<ItemType>* newNode;
  NodeType<ItemType>* predLoc;
  NodeType<ItemType>* location;
  if (IsEmpty()) {
    return;
  } else {
    FindItem(listData_, item, location, predLoc, found);
  }
}

template <class ItemType>
void CircularType<ItemType>::InsertItem(ItemType item) {
  if (IsFull()) {
    return;
  } else {
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData_ != NULL) {
      FindItem(listData_, item, location, predLoc, found);
      newNode->next = predLoc->next;
      predLoc->next = newNode;
      // item이 가장 큰 값이면 listData_ 를 바꿔준다.
      if (listData_->info < item) {
        listData_ = newNode;
      }
    } else {
      listData_ = newNode;
      newNode->next = newNode;
    }
    length_++;
  }
}

template <class ItemType>
void CircularType<ItemType>::DeleteItem(ItemType item) {
  NodeType<ItemType>* location;
  NodeType<ItemType>* predLoc;
  bool found;

  if (IsEmpty()) {
      return;
  } else {
    FindItem(listData_, item, location, predLoc, found);
    if (found == false)
      return;
    if (location == predLoc) {
      listData_ = NULL;
    } else {
      predLoc->next = location->next;
      // 마지막 list를 제거하는 경우
      if (location == listData_)
        listData_ = predLoc;
    }
    delete location;
    length_--;
  }
}

template <class ItemType>
void CircularType<ItemType>::ResetList() {
  currentPos_ = NULL;
}

template <class ItemType>
void CircularType<ItemType>::GetNextItem(ItemType& item) {
  if (currentPos_ == NULL)
    currentPos_ = listData_;
  else
    currentPos_ = currentPos_->next;
  item = currentPos_->info; // 처음 실행 하면 안죽나...
}

template <class ItemType>
void CircularType<ItemType>::FindItem(
    NodeType<ItemType>* listData, ItemType item,
    NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc,
    bool& found) {
  bool moreToSearch = true;

  location = listData->next; // 초기상태에서 여기로 들어오면 안죽나?
  predLoc = listData;
  found = false;
  while (moreToSearch && !found) {
    if (item < location->info) {
      moreToSearch = false; // 작은경우로 못찾음
    } else if (item == location->info) {
      found = true;
    } else {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != listData->next);
    }
  }
}

#endif  // CH6_CIRCULAR_LIST_H_
