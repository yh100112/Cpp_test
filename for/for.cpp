#include<iostream>
using namespace std;

int main() {
  int64_t i;
  int16_t cnt = 10;


  for (i = 0; i < cnt;) {
    cout << "hello " << i << endl; // i = 0
    --cnt;
  }

  bool test = true;
  for(i = 0; (i < cnt) || test;) {
    cout << i << endl;
    ++i;
  }
}
