#include<iostream>

using namespace std;

int main() {
  auto func1 = [] (int a, int b) {return a * b;};

  cout << "func1(2, 10) : " << func1(2,10) << endl;

  int num = 20;
  auto func2 = [&num] (int a) {num += a;};

  func2(100);

  cout << "num : " << num << endl;
}
