// CheckMatching.cpp
// 2018-07-18
// kdj6724@gmail.com

#include "ArrayStack.h"

inline void error(char* str) {
  printf("%s\n", str);
  exit(1);
}
bool CheckMatching(char* filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
    error("not exist");
  int nLine = 1;
  int nChar = 0;
  ArrayStack stack;
  char ch;

  while ((ch = getc(fp)) != EOF) {
    if (ch == '\n')
      nLine++;
    if (ch == '[' || ch == '{' || ch == '(') {
      stack.Push(ch);
    } else if (ch == ']' || ch == '}' || ch == ')') {
      int prev = stack.Pop();
      if ((ch == ']' && prev != '[') 
          || (ch == '}' && prev != '{')
          || (ch == ')' && prev != '('))
        break;
    }
  }
  fclose(fp);
  printf("%s result", filename);
  if (!stack.IsEmpty())
    printf("Error: %dLine %dchar\n", nLine, nChar);
  else
    printf("Ok: %dLine %dchar\n", nLine, nChar);
  return stack.IsEmpty();
}

int main(int argc, char* argv[]) {
  if (argc < 2)
    return -1;
  CheckMatching(argv[1]);
}
