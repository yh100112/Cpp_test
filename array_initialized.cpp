#include<iostream>
#include<cstring>

using namespace std;

int main() {
  int arr[5] = {1,2,3,4,5};

  // fill_n()으로 초기화
  // fill_n(arr,5,0);
  // for(auto& c : arr)
  //   cout << c << " "; // 0 0 0 0 0
  // cout << endl;
 

  memset(&arr[2],0,sizeof(arr[0]) * 3); // 1 2 0 0 0 으로 초기화됨
  for(auto& c : arr)
    cout << c << " ";
  cout << endl;

  // memset()으로 초기화
  memset(arr,0,sizeof(arr)); // 0 0 0 0 0 으로 초기화됨
  for(auto& c : arr)
    cout << c << " ";
  cout << endl;
}
