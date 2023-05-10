#include<iostream>
using namespace std;


void test(int32_t reel_indices[]) { // 배열 자체가 주소값이므로 주소값을 받을 수 있다. -> 그러므로 여기서 이 배열값을 바꾸면 원본이 바뀐다.
  int16_t i;
  for (i = 0; i < 5; ++i) {
    reel_indices[i] = 1;
  }
}

int main()
{
  int32_t test_indices[5] = {3,4,5,3,3};
  test(&test_indices[0]); // 배열은 어차피 주소값이므로 이렇게 배열의 시작 인덱스값의 주소를 보내도 된다.

  for(auto& t : test_indices) {
    cout << t << endl;
  }
}

