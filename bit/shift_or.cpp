#include<iostream>
using namespace std;

int main(){
  int16_t a = 1;
  cout << (a >> 1 & 1) << endl; // 순서대로 진행
  cout << (a & 1 << 1) << endl; // << 이 우선순위가 높아서 먼저 처리됨
}
