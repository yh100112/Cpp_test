#include<iostream>
using namespace std;

// slot.cpp:4825 ~ 4840 explanation
int main(){
  int paylines[5][3] = 
  {
    {3,4,5},
    {0,1,2},
    {6,7,8},
    {0,4,8},
    {6,4,2}
  };

  int cols_ = 3;

  int* paylines_ = new int[15];
  for(int i=0; i<5; i++){
    for(int j=0; j<cols_; j++){
      *(paylines_ + i * cols_ + j ) = paylines[i][j];
    }
  }
  
  for(int i=0; i<15; i++){
    cout << *(paylines_+i) << endl; // 3,4,5,0,1,2. . .
  }
  delete[] paylines_;
}

