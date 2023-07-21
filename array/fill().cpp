#include<bits/stdc++.h>
using namespace std;
int a[10];
int b[10][10];
int main() {
  fill(a, a + 10, 100); // 배열 a의 값을 모두 100으로 초기화
  fill(&a[0], &a[10], 100);
  fill(&a[0], &a[0] + 10, 200);

  fill(&b[0][0], &b[9][10], 2); // 2차원 배열 b의 값을 모두 2로 초기화
  fill(&b[0][0], &b[0][0] + 10*10, 2); // 이것도 가능
}

/*
fill(fisrt, last, val)
- [first, last) 까지 val로 초기화
*/