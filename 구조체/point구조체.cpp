#include<bits/stdc++.h>
using namespace std;

struct Point {
  int y,x; // 구조체 멤버변수
  Point(int y, int x) : y(y), x(x) {} // y,x를 받아 멤버변수 생성
  Point(){y = -1; x = -1;} // y,x가 정해지지 않은 경우 default로 -1, -1 설정

  // 연산자오버로딩 ( 구조체끼리 크고작음을 비교하는 기준을 잡음 )
  // 1순위 : x , 2순위 y를 기반으로 크고 작음을 판단
  // -> 정렬하면 x가 1순위, y가 2순위로 오름차순 정렬된다.
  bool operator < (const Point& a) const {
    if(x == a.x) return y < a.y;
    return x < a.x;
  }
};

/*
오버라이딩이 아니라 오버로딩인 이유
- operator +, -, *, / 등의 의미를 변경하지 않으며 그저 오퍼레이터의 대상이 바뀌는 것이기 때문

구조체 기반 sort()를 사용할 때 주의사항
- sort()함수 자체가 < 오퍼레이터를 기준으로 정렬하기 때문에 무조건 < 오퍼레이터를 오버로딩해야 함
*/
