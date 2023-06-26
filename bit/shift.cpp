#include<iostream>

using namespace std;

int main() {
  int16_t a = 0;
  a |= 1 << 1;
  cout << a << endl; // 2 : 0010

  cout << (a << 2) << endl; // 8 : 0100 -> 원본 a에는 영향 없음
  cout << a << endl; // 2

  a = a << 2; // 원본 a가 바뀜
  cout << a << endl; // 8
}
