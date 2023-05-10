#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
  ifstream readFile;
  readFile.open("test.txt"); // 파일 열기

  if(readFile.is_open()){
    //1. istream의 getline()
    /*
     * char tmp[256];
     * readFile.getline(tmp, 256);
     * cout << tmp << endl;
     */

    //2. std::getline
    while(!readFile.eof()){
      string str;
      getline(readFile, str); // std::getline()은 string타입으로 읽을 수 있어서 사용하기 좋다.
      cout << str << " ";
    }
    cout << endl;
    readFile.close();
  }
}
