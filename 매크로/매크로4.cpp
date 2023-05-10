#include<stdio.h>

#define INT_i(n)  int i##n = n; // ##  :  두 개의 토큰을 이어준다. 혹은 붙여준다.
#define SUM(res, n)  ((res) += (i##n))
#define PRINT(n)     printf("%d\n",i##n)

int main() {
  int ans = 0;
  int a;

  for (a = 0; a < 10; ++a) {
    INT_i(a);  // int i0 = 0;  ,  int i1 = 1; . . .
    PRINT(a);  // i0값 출력    ,  i1값 출력 . . .
    SUM(ans, a); // res += i0  ,  res += i1 . . .
  }

  printf("결과 : %d\n", ans);
}
