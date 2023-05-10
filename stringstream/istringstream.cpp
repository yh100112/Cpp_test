#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main() {
  string str = "abc def gg 11";
  string s[4];
  istringstream stt(str);


  // 방법 1.
  // stt >> s[0] >> s[1] >> s[2] >> s[3];
  
  // 방법 2.
  stt >> s[0];
  stt >> s[1];
  stt >> s[2];
  stt >> s[3];

  for(auto& v : s)
    cout << v << endl;
  //출력
  //abc
  //def
  //gg
  //11
  

  
}
