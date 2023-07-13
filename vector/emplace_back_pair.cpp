#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int,int>> v;
  v.emplace_back({1,1}); // emplace_back을 사용할 때는 이 형태로 pair를 넣을 수 없음.
  v.emplace_back(make_pair(1,1)); // emplace_back을 사용할 때는 pair를 넣을 수 없음.
  v.push_back({1,1});
}