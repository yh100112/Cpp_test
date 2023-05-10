//string에서 int형 뽑아내는 방법

#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main() {
  int num;
  string text = "123 456\n789 012";
  
  stringstream ss;
  ss.str(text); // 초기화 -> stream에 text을 대입

  // 뽑아내고자 하는 int형 값을 출력
  while(ss >> num) {
    cout << num << endl; // 123, 456, 789, 12 이렇게 4번 출력됨
  }

  string s;
  string str = "hello world!\nhell world";

  stringstream sss(str); // 초기화 -> sss에 str을 대입
  while(sss >> s) {
    cout << s << endl; // hello, world!, hell, world 이렇게 4번 출력됨
  }

}
