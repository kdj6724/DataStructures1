// stack_type.h
// 2018-07-20
// kdj6724@gmail.com
#ifndef CH5_STACK_TYPE_H_
#define CH5_STACK_TYPE_H_
class FullStack {
};
class EmptyStack {
};

typedef char ItemType;
struct NodeType;
class StackType {
public:
  StackType();
  virtual ~StackType();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(ItemType item);
  void Pop();
  ItemType Top() const;
private:
  NodeType* topPtr_;
};

struct NodeType {
  ItemType info;
  NodeType* next;
};
#endif  // CH5_STACK_TYPE_H_
