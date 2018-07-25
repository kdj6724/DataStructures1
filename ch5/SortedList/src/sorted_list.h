// sorted_list.h
// 2018-07-24
// kdj6724@gmail.com
#ifndef CH5_SORTED_LIST_H_
#define CH5_SORTED_LIST_H_
template <class ItemType>
struct NodeType {
  ItemType info;
  NodeType* next;
};

template <class ItemType>
class SortedType {
public:
  SortedType();
  virtual ~SortedType();
  bool IsFull() const;
  int LengthIs() const;
  void MakeEmpty();
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
private:
  NodeType<ItemType>* listData_;
  int length_;
  NodeType<ItemType>* currentPos_;
};

template <class ItemType>
SortedType<ItemType>::SortedType() {
  length_ = 0;
  listData_ = NULL;
}

template <class ItemType>
SortedType<ItemType>::~SortedType() {
  MakeEmpty();
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const {
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
int SortedType<ItemType>::LengthIs() const {
  return length_;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty() {
  NodeType<ItemType>* tempPtr;
  while (listData_ != NULL) {
    tempPtr = listData_;
    listData_ = listData_->next;
    delete tempPtr;
  }
  length_ = 0;
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
  bool moreToSearch;
  NodeType<ItemType>* location;
  location = listData_;
  found = false;
  moreToSearch = (location != NULL);
  while (moreToSearch && !found) {
    if (item == location->info) {
      found = true;
      item = location->info;
    } else {
      location = location->next;
      moreToSearch = (location != NULL);
    }
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item) {
  if (IsFull()) {
    return;
  } else {
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool moreToSearch;
    location = listData_;
    moreToSearch = (location != NULL);
    while (moreToSearch) {
      if (location->info < item) {
        predLoc = location;
        location = location->next;
        moreToSearch = (location != NULL);
      } else {
        moreToSearch = false;
      }
    }
    newNode = new NodeType<ItemType>;
    newNode->info = item; 

    if (predLoc == NULL) {
      newNode->next = listData_;
      listData_ = newNode;
    } else {
      predLoc->next = newNode;
      newNode->next = location;
    }
    length_++;
  }
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
  NodeType<ItemType>* location;
  NodeType<ItemType>* tempLocation;
  location = listData_;
  if (item == listData_->info) {
    tempLocation = location;
    listData_ = listData_->next;
      std::cout << "item " << item << std::endl;
      std::cout << "list " << listData_->info << std::endl;
  } else {
    while (!(item != (location->next)->info)) {
      location = location->next;
      std::cout << "item " << item << std::endl;
      std::cout << "next " << location->next->info << std::endl;
    }
    std::cout << "item " << item << std::endl;
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length_--;
}

template <class ItemType>
void SortedType<ItemType>::ResetList() {
  currentPos_ = NULL;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item) {
  if (currentPos_ == NULL) {
    currentPos_ = listData_;
  } else {
    currentPos_ = currentPos_->next;
  }
  item = currentPos_->info; // 처음 실행 하면 안죽나...
}

#endif  // CH5_SORTED_LIST_H_
