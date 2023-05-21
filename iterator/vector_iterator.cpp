#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;
  for(int i=0;i<7;i++){ v.push_back(10*i); } // 0 10 20 30 40 50 60

  vector<int>::iterator iter;
  iter = v.begin();

  cout << iter[1] << endl; // 10
  iter += 2; // iter 두개 다음으로 이동
  cout << *iter << endl; // 20
  cout << iter[0] << endl; // 20

  for(iter = v.begin(); iter != v.end(); iter++){ cout << *iter << " "; }
  cout << endl;
  // for문을 다 돈 후 현재 iterator는 v.end()를 가리킴
}
