#include<iostream>
using namespace std;

// typedef로 열거형 별칭 지정하기
typedef enum _DayOfWeek { // 열거형 이름 : _DayOfWeek
  Sunday,
  Monday,
  Tuesday
} DayOfWeek;   //  typedef를 사용하여 열거형 별칭을 DayOfWeek로 정의

// typedef로 열거형 별칭 지정하기2
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
  DayOfWeek test = Sunday; // typedef 열거형 변수 선언1
  DayOfWeek2 test2 = bbb;  // typedef 열거형 변수 선언2
  week = C;

  cout << test << endl;  // 0
  cout << test2 << endl; // 1 
  cout << week << endl;  // 2
}


