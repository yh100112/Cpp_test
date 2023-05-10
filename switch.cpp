#include<iostream>
using namespace std;

int main() {
  int16_t ans = 10;

  switch(ans) {
    case 1: case 3: case 5:
      cout << "출력!" << endl;
      break;
    default:
      cout << "미출력!" << endl;
  }
}
