// run_time.cpp
// 2018-07-17
// kdj6724@gmail.com

#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  clock_t start, finish;
  double duration;

  start = clock();
  for (int i=0; i<100; i++) {
    printf("i = %d\n", i);
  }
  finish = clock();
  duration = (double)(finish-start) / CLOCKS_PER_SEC;
  printf("%f seconds\n", duration);
  return 0;
}

