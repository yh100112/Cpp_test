#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<boost/algorithm/string/split.hpp>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

int main(){
  string text = "Lorem ipsum dolar sit amet, consectetur adjasdf elios.";
  vector<string> words;

  boost::split(words, text, isspace); // " "을 기준으로 text를 나눠서 words 컨테이너에 저장한다.
  for(const auto &item : words){
    cout << item << "; ";
  }
  cout << endl;
  return 0;
}

/*
 * isspace 함수객체를 지정하여 두번째 매개변수에 주어진 문자열에서 공백을 기준으로 토큰으로 분할한다.
 * boost::split에는 토큰화된 문자열을 저장할 대상 시퀀스 컨테이너( 연속 컨테이너 )가 필요하므로 첫번째 매개변수에 문자열을 저장할 대상 컨테이너를 전달한다.
 * boost::split();
 * 첫 번째 매개변수 : 토큰화된 문자열을 저장할 시퀀스 컨테이너( == 연속 컨테이너 ex) vector,list 등 )
*/

