#include<iostream>
#include<cstring>
using namespace std;

const int16_t MAX_EXTRAS = 200;

int64_t extras_[MAX_EXTRAS];

int16_t symbol_id[16] = {21,22,23,24,25,26,27,28,21,22,23,24,25,26,27,28};

int main () {
  int i,j;
  memset(extras_, 0, sizeof(extras_));
  
  for (i = 0; i < 7; ++i) {
    int64_t id = (int64_t)symbol_id[i] << (8 * i);
    extras_[0] |= id; // 처리할 심볼을 넣을때마다 비트를 8만큼 왼쪽으로 이동시켜서 넣는다. ( 1byte당 한개의 심볼 id값을 bitset으로 저장 )
  }
  cout << extras_[0] << endl;
  
  for (i = 0; i < 7; ++i) {
    // int64_t id = (int64_t)symbol_id[i+7] << (8 * i);
    // extras_[1] |= id; // 처리할 심볼을 넣을때마다 비트를 8만큼 왼쪽으로 이동시켜서 넣는다. ( 1byte당 한개의 심볼 id값을 bitset으로 저장 )
    extras_[1] |= (int64_t)symbol_id[i+7] << (8 * i);
  }
  cout << extras_[1] << endl;
}
