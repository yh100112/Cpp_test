#include<stdio.h>
#define PRINT(s) printf(#s)
#define print2(s) printf(s)

int main() {
  PRINT(this is test code\n); // this is test code 출력 -> #는 받아온 매크로변수를 문자열로 바꿔주는, 즉 앞뒤에 따옴표를 붙이는 것과 같은 의미이다.
  print2("this is test code"); // this is test code 출력 -> 따옴표 안하면 오류
}

