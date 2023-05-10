#include<iostream>
#include<random>
using namespace std;

int32_t get_rand(int32_t range)
{
  random_device rd; // "난수 생성기" ( 생성기로는 이것만 쓰는 듯 )
  default_random_engine generator(rd()); // default_random_engine, mt19937, mt19937_64 모두 "난수 생성 엔진" 종류 중 하나이다.
 
  if (range == 0)
    return 0;

  uniform_int_distribution<int32_t> distribution(0, range - 1); // "분포기"
  return distribution(generator);
}

int main(){
  if(get_rand(3) == 0){
    cout << "3분의 1 확률로 당첨!" << endl;
  }

  if(get_rand(5) == 0){
    cout << "5분의 1 확률로 당첨!" << endl;
  }

}

/*
 * 난수 생성은
 * 1. 난수 생성기
 * 2. 난수 생성 엔진
 * 3. 분포기
 * -> 이 세개가 있어야 제대로 된 난수를 생성해 낼 수 있다.
 */
