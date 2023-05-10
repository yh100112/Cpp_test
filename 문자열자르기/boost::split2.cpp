#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
// #include<boost/algorithm/string/split.hpp>
#include<boost/algorithm/string.hpp> // is_any_of() 사용 위한 헤더파일

using namespace std;

int main(){
  string text = "Lorem ipsum dolar sit amet, consectetur adjasdf elios.";
  vector<string> words;

  boost::split(words, text, boost::is_any_of(" ")); // " "을 기준으로 text를 나눠서 words 컨테이너에 저장한다.
  for(const auto &item : words)
    cout << item << "; ";
  cout << endl;

  string text2 = "aaa,bbb,ccc,ddd";
  vector<string> words2;
  boost::split(words2, text2, boost::is_any_of(",")); // ","을 기준으로 text를 나눠서 words 컨테이너에 저장한다.
  for(const auto &item : words2)
    cout << item << " ";
  cout << endl;

  string text3 = "aaa bbb ccc ddd";
  vector<string> words3;

  boost::split(words3, text3, [](char c){return c == ' ';}); // ' '를 기준으로 text3을 나눠서 words3 컨테이너에 저장한다. 
  for(const auto &item : words3)
    cout << item << " ";
  cout << endl;

  return 0;
}
