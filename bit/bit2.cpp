#include<iostream>
using namespace std;

int main() {
  int32_t hold = 4000; // 1111 1010 0000 
  int16_t i,j;
  int16_t arr[12] = {0,};

  for (i = 0; i < 12; ++i) {
    if (hold & (1 << i)) // 0000 0000 0001, 0000 0000 0010 ... 등등 해당 비트가 켜져있는지 확인 ( 해당 위치의 비트가 둘다 1이면 1 반환해서 true로 if문을 탈거임
      arr[i] = 1;
  }

  int16_t cnt = 0;
  for (i = 0; i < 12; ++i) {
    cout << arr[i] << " ";
    ++cnt;
    if(cnt % 5 == 0) cout << endl;
  }
  cout << endl;
}
