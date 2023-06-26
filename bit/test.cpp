#include<iostream>

using namespace std;

int main() {
  int16_t a = 0;
  a |= 1 << 1;
  cout << a << endl; // 2 : 0010
  a |= 1;
  cout << a << endl; // 3 : 0011
  a << 2;
  cout << a << endl;
}
