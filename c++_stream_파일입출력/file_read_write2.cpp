#include<fstream>
#include<iostream>
using namespace std;

int main(){
  string filePath = "test.txt";

  //write file
  ofstream writeFile(filePath.data()); // string.data() : string -> char*로 변경
  if(writeFile.is_open()){
    writeFile << "Hello world!\n";
    writeFile << "This is C++ File Contents. \n";
    writeFile.close();
  }


  //read file
  ifstream openFile(filePath.data());
  if(openFile.is_open()){
    string line;
    while(getline(openFile, line)){
      cout << line  << endl;
    }
    openFile.close();
  }
}
