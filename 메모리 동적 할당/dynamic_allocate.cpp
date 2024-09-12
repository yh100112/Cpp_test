#include<iostream>
// #include<malloc.h>
using namespace std;

int main(){
  // 변수 동적할당
  int *point = new int;
  *point = 100;
  cout <<*point << endl;
  delete point;

  cout << "---" << endl;

  // 배열 동적할당
  // 동적할당으로 만든 배열(malloc이나 new로 생성한 것)은 길이를 알 수 없다.
  int *point2 = new int[5];
  for(int i=0; i<5; i++){
      point2[i] = i;
      cout << point2[i] << endl;
  }
  cout << sizeof(point2) << endl; // 8바이트 -> 포인터변수 크기
  cout << sizeof(*point2) <<endl; // 4바이트 -> 들어있는 값 크기
  cout << sizeof(point2[0]) << endl; // 4
  cout << *point2<<endl; // 0
  delete[] point2; // 배열 형태 메모리 할당해제
}
