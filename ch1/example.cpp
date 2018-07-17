// example.cpp
// 2018-07-17
// kdj6724@gmail.com
#include <iostream>
#include <stdlib.h>

int sumAlgorithmA(int n) {
  int res = 0;
  res = n*(n + 1)/2;
  return res;
}

int sumAlgorithmB(int n) {
  int res = 0;
  for(int i=1; i<=n; i++) {
    res = res + i;
  }
  return res;
}

int sumAlgorithmC(int n) {
  int res = 0;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<i; j++) {
      res = res + 1;
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  int val = 0;
  if (argc < 2) {
    printf("argument error\n");
    return -1;
  }
  val = atoi(argv[1]);
  std::cout << "sumAlgorithmA " <<  sumAlgorithmA(val) << std::endl;
  std::cout << "sumAlgorithmB " <<  sumAlgorithmB(val) << std::endl;
  std::cout << "sumAlgorithmC " <<  sumAlgorithmC(val) << std::endl;
  return 0;
}
