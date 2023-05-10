#include<iostream>
using namespace std;

int main(){
  int16_t i;
  for(i = 0; i < 5; ++i) {
    cout << "i : " << i << endl;
  }

  cout << "for 종료 후 i : " << i << endl;

  int32_t rand = 99;
  for (i = 0; i < 1; ++i)
    if (rand < 100)
      break;
  cout << i << endl; // 0
}
