#include<iostream>
using namespace std;

int main() {
  int32_t hold = 905736;
  int16_t i,j;
  int16_t arr[20] = {0,};

  for (i = 0; i < 20; ++i) {
    if (hold & (1 << i)) // 켜져있는 비트를 확인해서 켜져있다면 -1을 배열에 넣어줌 -> 심볼의 위치를 찾아주는 것임
      arr[i] = -1;
  }

  int16_t cnt = 0;
  for (i = 0; i < 20; ++i) {
    cout << arr[i] << " ";
    ++cnt;
    if(cnt % 5 == 0) cout << endl;
  }
}
