#include<iostream>
#include<string>

using namespace std;

int main() {
  int result1 = 1;
  int result2 = 2;
  int result3 = 3;
  int result4 = 4;

  // 외부 변수 result1, result2를 복사해서 람다 함수 내부에서 사용 가능
  [result1, result2] (int a, int b) {
    cout << "result1, result2 : " << result1 << ", " << result2 << endl;
    cout << "result1 + a + b : " << result1 + a + b << endl;
  } (10, 20);

  // 외부 변수 result3, result4를 참조해서 람다 함수 내부에서 사용 가능
  [&result3, &result4] (int a, int b) {
    result3 = 22222;
    cout << "(내부) result3 : " << result3 << endl;
    result4 = a + b;
  } ( 10, 20);
  
  // 모든 외부 변수를 참조해서 람다 함수 내부에서 사용가능
  [&] (int a, int b) {
    result3 = 200;
    cout << "(내부2) result3 : " << result3 << endl;
    result4 = a + b;
    result4 = 300;
  } ( 10, 20);

  cout << "(외부) result3, result4 : " << result3 << ", " << result4 << endl;
}

/*
람다 캡처
맨 앞에 있는 []를 캡처라고 함
캡처는 람다 외부에 정의되어 있는 변수나 상수를 람다 내부에서 사용하기 위해 사용

모든 외부 변수에 대해 참조를 해서 람다 내부에서 사용  ->  [&]
모든 외부 변수에 대해 복사를 해서 람다 내부에서 사용  ->  [=]

*/
