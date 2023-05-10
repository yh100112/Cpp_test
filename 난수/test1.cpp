#include<random>
#include<iostream>
using namespace std;

int main(){
  mt19937_64 mtRand; // 난수 생성기(64비트 버전) 아직 시드값은 없다.
  for(int i=0; i<7; i++){
    cout << mtRand() << endl; // 호출마다 난수 생성 -> 하지만 시드값을 주지 않아 항상 동일한 숫자가 나옴
  }

  cout << endl << endl;
  random_device rng;
  for(int i=0; i<7; i++){
    cout << rng() << endl;
  }

}
