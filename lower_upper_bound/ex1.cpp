#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a {1,2,3,5,7,8,10};
  cout << *lower_bound(a.begin(), a.end(), 3) << endl; // 3
  cout << *upper_bound(a.begin(), a.end(), 3) << endl; // 5
}