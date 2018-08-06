// binary_search_tree.h
// 2018-07-29
// kdj6724@gmail.com
#ifndef CH8_TREE_TYPE_H_
#define CH8_TREE_TYPE_H_
#include <iostream>
template <class ItemType>
struct TreeNode {
  ItemType info;
  TreeNode<ItemType>* left;
  TreeNode<ItemType>* right;
};

template <class ItemType>
class TreeType {
public:
  TreeType();
  TreeType(const TreeType<ItemType>& originalTree);
  virtual ~TreeType();
  void operator=(const TreeType<ItemType>& originalTree);
  void MakeEmpty();
  bool IsFull() const;
  bool IsEmpty() const;
  int LengthIs() const;
  void RetrieveItem(ItemType& item, bool& found) const;
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void Print(std::ofstream& outFile);
protected:
  void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
  void Destroy(TreeNode<ItemType>*& tree);
  int CountNodes(TreeNode<ItemType>* tree);
  void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);
  void Insert(TreeNode<ItemType>*& tree, ItemType item);
  void DeleteNode(TreeNode<ItemType>*& tree);
  void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);
  void Delete(TreeNode<ItemType>*& tree, ItemType item);
  void PrintTree(TreeNode<ItemType>* tree, std::ofstream& outFile);
private:
  TreeNode<ItemType>* root_;
};

template <class ItemType>
TreeType<ItemType>::TreeType() {
  root_ = NULL;
}

template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree) {
  CopyTree(root_, originalTree.root_);
}

template <class ItemType>
TreeType<ItemType>::~TreeType() {
  Destroy(root_);
}

template <class ItemType>
void TreeType<ItemType>::operator=(const TreeType<ItemType>& originalTree) {
  {
    if (&originalTree == this)
      return;
    Destroy(root_);
    CopyTree(root_, originalTree.root_);
  }
}

template <class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree) {
  if (originalTree == NULL) {
    copy = NULL;
  } else {
    copy = new TreeNode<ItemType>;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}

template <class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& tree) {
  if (tree != NULL) {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

template <class ItemType>
bool TreeType<ItemType>::IsFull() const {
  TreeNode<ItemType>* location;
  try {
    location = new TreeType;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const {
  return root_ == NULL;
}

template <class ItemType>
int TreeType<ItemType>::CountNodes(TreeNode<ItemType>* tree) {
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template <class ItemType>
int TreeType<ItemType>::LengthIs() const {
  return CountNodes(root_);
}

template <class ItemType>
void TreeType<ItemType>::Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found) {
  if (tree == NULL) {
    found = false;
  } else if (item < tree->info) {
    Retrieve(tree->left, item, found);
  } else if (item > tree->info) {
    Retrieve(tree->right, item, found);
  } else {
    item = tree->info;
    found = true;
  }
}

template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found) const {
  Retrieve(root_, item, found);
}

template <class ItemType>
void TreeType<ItemType>::Insert(TreeNode<ItemType>*& tree, ItemType item) {
  if (tree == NULL) {
    tree = new TreeNode<ItemType>;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  } else if (item < tree->info) {
    Insert(tree->left, item);
  } else {
    Insert(tree->right, item);
  }
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item) {
  Insert(root_, item);
}

template <class ItemType>
void TreeType<ItemType>::GetPredecessor(TreeNode<ItemType>* tree, ItemType& data) {
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

template <class ItemType>
void TreeType<ItemType>::DeleteNode(TreeNode<ItemType>*& tree) {
  ItemType data;
  TreeNode<ItemType>* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL) {
    tree = tree->right;
    delete tempPtr;
  } else if (tree->right == NULL) {
    tree = tree->left;
    delete tempPtr;
  } else {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);
  }
}

template <class ItemType>
void TreeType<ItemType>::Delete(TreeNode<ItemType>*& tree, ItemType item) {
  if (item < tree->info)
    Delete(tree->left, item);
  else if (item > tree->info)
    Delete(tree->right, item);
  else
    DeleteNode(tree);
}

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item) {
  Delete(root_, item);
}

template <class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* tree, 
    std::ofstream& outFile) {
  if (tree != NULL) {
    PrintTree(tree->left, outFile);
    outFile << tree->info;
    PrintTree(tree->right, outFile);
  }
}

template <class ItemType>
void TreeType<ItemType>::Print(std::ofstream& outFile) {
  PrintTree(root_, outFile);
}

#endif  // CH8_TREE_TYPE_H_
