#include<iostream>
#include<vector>
using namespace std;

int main(){
#ifndef KOREA
  cout << "zzz" << endl; // 현재 우분투 서버는 해외에 있으므로 코리아가 아니라 이걸 출력
#else
  cout << "korea!!" << endl;
#endif
}
