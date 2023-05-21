#include<iostream>
using namespace std;

int main(){
  int *pnum = new int;  // 동적 메모리 할당
  cout << "1. heap 메모리 위치 :" << pnum << endl; // 힙메모리를 할당받음

  pnum = new int; 
  // 처음 할당받은 힙메모리 위치를 해지해주지 않고 pnum에 다른 값을 넣어버림. 
  // pnum에 다른 값이 들어있어서 처음 할당받은 메모리 주소를 접근할 방법이 없어짐
  // 처음 메모리 주소를 해제할 방법이 없음(처음 힙메모리 위치의 주소가 유실되었기 때문에)

  cout << "2. heap 메모리 위치 :" << pnum << endl; //
  delete pnum;

  return 0;
}