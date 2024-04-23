#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a {1,2,3,3,3,3,4,100};
  cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3) << endl; // 숫자 3의 개수 : 6 - 2 = 4 

  vector<int> v {1, 2, 8, 34};
  cout << *lower_bound(v.begin(), v.end(), 10) << endl; // 34 -> 10이 없으면 10보다 큰 값 중 제일 10과 가까운 값 위치를 반환 
  cout << *lower_bound(v.begin(), v.end(), 3) << endl;  // 8
  cout << *lower_bound(v.begin(), v.end(), 35) << endl;  // 이 경우는 35보다 큰 값이 없으므로 0 반환 
  cout << lower_bound(v.begin(), v.end(), 35) - v.begin() << endl;  // 4  -> 35보다 큰 값이 없으므로 v.end()를 가리킴

  vector<int> v2 {0,0,0,0};
  cout << lower_bound(v.begin(), v2.end(), 10) - v2.begin() << endl; // 4
}