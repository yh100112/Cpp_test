#include<iostream>
using namespace std;

enum SYMBOLS : int16_t {
  SYMBOL_1 = 0,
  SYMBOL_2 = 1,
  SYMBOL_3 = 2,
  SYMBOL_4 = 3,
  SYMBOL_5 = 4,
};

// error : enum변수명은 숫자로 시작할 수 없음
// 1st, 2nd 가 안 됨
typedef enum {
  // 1st,
  // 2nd,
  trd
} test;

int main(){
  cout << SYMBOL_3 << endl;
  return 0;
}




