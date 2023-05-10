#include<iostream>
using namespace std;

int main(){
  int a[5] = {1,2,3,4,5};
  cout << a << endl;// 0x7ffe... 
  cout << *a << endl; // 1
  cout << *(a + 1) << endl; // 2
  cout << *a + 9 << endl; //10


  int *b = a;
  cout << *b << endl;

}
