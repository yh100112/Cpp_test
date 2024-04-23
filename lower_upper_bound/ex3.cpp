#include<bits/stdc++.h>
using namespace std;

int main() {
  int a[4] = {0};
  cout << lower_bound(a, a, 10) - a << endl; // 가리키는 위치 0
  cout << lower_bound(a, a + 1, 10) - a << endl; // 가리키는 위치 1
  cout << lower_bound(a, a + 4, 10) - a << endl; // 가리키는 위치 4
}