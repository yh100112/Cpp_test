#include <iostream>
using namespace std;

void test(int16_t* paylines_)
{
  for (int16_t i = 0; i < 10; ++i) {
    cout << *(paylines_ + i) << endl;
  }
}
// 0 1 2 3 0 0 0 0 0 0

int main() {
  int16_t* paylines_ = new int16_t[10];
  paylines_[0] = 0;
  paylines_[1] = 1;
  paylines_[2] = 2;
  paylines_[3] = 3;

  test(paylines_);
}
