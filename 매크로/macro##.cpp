#include<stdio.h>
#define INT_i(n)  int i##n;  // ##  :  두 개의 토큰을 이어준다. 혹은 붙여준다.

// 위 매크로는 받아온 n이라는 변수를 i##n과 같이 i 하고 붙여준 int형 변수를 선언하게 된다.
// -> int i##n;   ==  int i0;  과 같은 의미  -> i0 라는 int형 변수를 선언해준 것
