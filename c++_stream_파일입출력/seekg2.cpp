#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream input("input.txt");

  input.seekg(0, input.end);
  cout << "파일의 길이는 " << input.tellg() << "입니다." << endl;
  cout << "마지막 위치는 : " << (char)input.peek() << endl; // 문자 '\0'이 나옴


  input.seekg(-2, input.end); // input.end -1 위치는 개행문자가 있다. 
  cout << "마지막 글자는 " << (char)input.peek() << endl; 

  input.close();
  return 0;
}

//즉, input.seekg(0, input.end) => '\0'
//    input.seekg(-1, input.end) => '\n'
//    input.seekg(-2, input.end) => 마지막 글자
//    .txt파일의 마지막에는 무조건 \n\0이렇게 뒤에 들어간다.
