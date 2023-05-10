#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int> v;

  v.push_back(1);
  v.push_back(1);
  v.push_back(6);
  v.push_back(8);

  cout << v.size() << endl;

  if(find(v.begin(), v.end(), 0) == v.end()){
    cout << "not exist" << endl;
  }

  if(find(v.begin(), v.end(), 6) != v.end()){
    cout << find(v.begin(), v.end(),6) - v.begin() << endl; // 인덱스 확인
  }
}
