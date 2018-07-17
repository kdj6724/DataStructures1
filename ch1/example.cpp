// example.cpp
// 2018-07-17
// kdj6724@gmail.com
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

// O(1)
int sumAlgorithmA(int n) {
  int res = 0;
  res = n*(n + 1)/2;
  return res;
}

// O(n)
int sumAlgorithmB(int n) {
  int res = 0;
  for(int i=1; i<=n; i++) {
    res = res + i;
  }
  return res;
}

// O(n^2)
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
  clock_t start, finish;
  double duration;
  int val = 0;
  if (argc < 2) {
    printf("argument error\n");
    return -1;
  }
  val = atoi(argv[1]);
  start = clock();
  std::cout << "sumAlgorithmA " <<  sumAlgorithmA(val);
  finish = clock();
  duration = (double)finish - start;
  printf(" -> runtime : %f\n", duration);
  
  start = clock();
  std::cout << "sumAlgorithmB " <<  sumAlgorithmB(val);
  finish = clock();
  duration = (double)finish - start;
  printf(" -> runtime : %f\n", duration);

  start = clock();
  std::cout << "sumAlgorithmC " <<  sumAlgorithmC(val);
  finish = clock();
  duration = (double)finish - start;
  printf(" -> runtime : %f\n", duration);
  return 0;
}
