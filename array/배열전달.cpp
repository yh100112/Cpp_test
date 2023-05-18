#include<iostream>
using namespace std;


void test(int32_t reel_indices[]) { // 배열 자체가 주소값이므로 주소값을 받을 수 있다. -> 그러므로 여기서 이 배열값을 바꾸면 원본이 바뀐다.
  int16_t i;
  cout << sizeof(reel_indices) / sizeof(reel_indices[0]) << endl; // 함수 내부에서 매개변수로 받은 배열의 크기를 sizeof()를 사용해 만들면 오류가 발생한다!! -> 사용 X
  for (i = 0; i < 5; ++i) {
    reel_indices[i] = 1;
  }
}

/*
배열 매개변수는 포인터로 취급된다.
그렇기 때문에 sizeof(reel_indices) / sizeof(reel_indices[0]  =>  sizeof(int*) / sizeof(int)가 되어 2가 된다. ( 포인터의 크기는 8바이트이므로 )
*/

int main()
{
  int32_t test_indices[5] = {3,4,5,3,3};
  test(&test_indices[0]); // 배열은 어차피 주소값이므로 이렇게 배열의 시작 인덱스값의 주소를 보내도 된다.

  for(auto& t : test_indices) {
    cout << t << endl;
  }
}

