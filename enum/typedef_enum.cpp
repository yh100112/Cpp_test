#include<iostream>
using namespace std;

// typedef로 열거형 별칭 지정하기
typedef enum { 
  aaa,
  bbb,
  ccc
} DayOfWeek2;


// 열거형을 정의하는 동시에 열거형 변수 선언하기
enum Day {
  A,
  B,
  C
} week;

int main() {
  DayOfWeek2 test2 = bbb;  // typedef 열거형 변수 선언2
  week = C;
  cout << test2 << endl; // 1 
  cout << week << endl;  // 2
}


