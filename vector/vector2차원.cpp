#include<iostream>
#include<vector>
using namespace std;

int main() {
  vector<vector<int16_t>> a;
  vector<int16_t> b;
  b.emplace_back(1); 
  b.emplace_back(2); 
  b.emplace_back(3); 

  a.emplace_back(b); // 형태 그대로 벡터를 넣어줘야 한다!!
  // a[0].emplace_back(2); -> error

  cout << a[0][0] << endl; // 1
}
