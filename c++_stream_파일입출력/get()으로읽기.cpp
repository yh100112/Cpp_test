#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream file("input.txt");

  while(!file.eof())
    cout << (char)file.get();
}
