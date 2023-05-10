#include<iostream>
using namespace std;


int main(){
  int paylines[5][3] = 
  {
    {3,4,5},
    {0,1,2},
    {6,7,8},
    {0,4,8},
    {6,4,2}
  };

  int (*paylines_)[3] = paylines; 

  cout << *paylines_ << endl;//0x7ffdfa... 
  
  for(int i=0; i<15; i++){
    cout << *(*paylines_+i) << endl; // 3,4,5,0,1,2. . .
  }


  cout << *paylines_ << endl;// 0x7ffdfa... -> 컬럼(세로줄) 첫 번째의 주소가 나옴( 3이 있는 곳의 주소값 ) 
}

