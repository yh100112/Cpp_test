#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  a.push_back(6);

  a.erase(a.begin()); // 0번 인덱스 즉, 제일 첫번째 원소인 1을 삭제함

  // for(auto c : a)
  //   cout << c << endl;

  for(int i=0; i<a.size(); i++)
    cout << a[i] << " ";
  cout << endl;

  a.erase( remove( a.begin(), a.end(), 3 ), a.end()); // 원소 3 삭제

  for(int i=0; i<a.size(); i++)
    cout << a[i] << " ";

  cout << endl;
}
