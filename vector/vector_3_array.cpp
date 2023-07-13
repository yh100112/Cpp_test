#include<vector>
#include<iostream>
using namespace std;

int main()
{
  vector<vector<vector<int>>> test; // vector test를 선언만 한 상태 메모리에 실제 할당된 공간은 없음

  // resize를 사용해 test를 원하는 크기만큼 메모리 공간에 할당
  // resize로 필요한 사이즈만큼 할당하지 않으면 1차원 배열은 그냥 emplace_back해도 오류가 없지만
  // 2, 3차원 벡터라면 그 곳에 인덱스로 접근해야 하므로 없는 곳에 접근하는 게 되서 segfault가 발생한다.
  // 만약 resize를 하지 않고 값을 넣고 싶으면 test를 선언할 때 구조대로 vector<>를 만들어서 vector 형태 그대로 넣어야 함
  test.resize(3);
  for (auto& v : test) {
    v.resize(3);
    // for (auto& vv: v)  // !1. 마지막 3차원 배열의 3차원 부분까지 resize를 하면 0으로 값이 들어가서 밑에서 emplace_back으로 값을 넣을 때 뒤로 들어감
    //   vv.resize(3);
  }


  int i,j,k;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      for (k = 0; k < 3; ++k) {
        test[i][j].emplace_back(k);
        // test[i][j][k] = k;  // ! "1."의 주석을 해제하고 resize해주면 이렇게 넣어줄 수 있음 이미 0으로 값이 들어가 있는 상태이므로
      }
    }
  }
}
