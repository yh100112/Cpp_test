#include<iostream>

using namespace std;

int main() {
  int16_t a = 0;
  a |= 1 << 1;
  cout << a << endl; // 2 : 0010

  a |= 1 << 2; //! 1 << 2부터 수행된 후 or 연산이 수행됨
  cout << a << endl;

  a |= 1 << 1 + 2; 
  // 1. (1+2) 부터 수행
  // 2. 1 << (1+2) 수행
  // 3. |= 수행
  cout << a << endl;
}
