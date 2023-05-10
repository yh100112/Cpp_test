#include <iostream>

using namespace std;

int64_t my_pow(int16_t a, int16_t n)
{
  int16_t i;
  int64_t num = 1;
  for (i = 0; i < n; ++i) {
    num = num * a;
  }
  cout << num << endl;
  return num;
}

int main() {
  my_pow(2,1);
}
