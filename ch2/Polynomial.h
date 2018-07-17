// Polynomial.h
// 2018-07-17
// kdj6724@gmail.com
#include <cstdio>
#ifndef CH2_POLYNOMIAL_H_
#define CH2_POLYNOMIAL_H_
#define MAX_DEGREE 80
class Polynomial {
private:
  int degree_;
  float coef_[MAX_DEGREE];
public:
  Polynomial() { 
    degree_ = 0;
  }
  void Read() {
    printf("다항식의 최고 차수를 입력하시오: ");
    scanf("%d", degree_);
    printf("각 항의 계수를 입력 하시오 (총 %d개): ", degree_ + 1);
    for (int i=0; i<=degree_; i++)
      scanf("%f", coef + i);
  }
  void Display(char* str=" Poly = ") {
    printf("\t %s", str);
    for(int i=0; i<degree_; i++)
      printf("%5.1f x^%d + ", coef_[i], degree_ - i);
    printf("%4.1f\n", cofe_[degree_]);
  }
  void Add(Polynomial a, Polynamial b) {
    if (a.degree_ > b.degree_) {
      *this = a;
      for (int i=0; i<=b.degree_; i++)
        coef_[i+degree_
    } else {
    }
  }
};
#endif  // CH2_POLYNOMIAL_H_
