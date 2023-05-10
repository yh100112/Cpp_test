#include<random>
#include<iostream>
using namespace std;

int main(){
  random_device rd; // 난수를 생성한다. 그래서 다른 난수 생성엔진의 시드 초기화나 암호화 용도로 사용할 수 있다.
  default_random_engine rng(rd()); //  mt19937같은 난수 생성 엔진의 종류 중 하나
  
  uniform_int_distribution<int32_t> dist1(-3,3); // -3과 3사이의 정수 값을 가짐 -3,-2,-1,0,1,2,3

  cout << "dist1의 최솟값 : " << dist1.min() << endl;
  cout << "dist1의 최댓값 : " << dist1.max() << endl;

  for(int i=0; i<7; i++){
    cout << dist1(rng) << endl;
  }

}
