#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
  string text = "Lorem ipsum dolar sit amet, consectetur adjasdf elios.";
  stringstream ss(text);

  vector<string> words; // 자른 문자열을 저장할 컨테이너
  string word;          // 자른 문자열 하나하나를 저장할 매개변수
  while(getline(ss, word, ' ')){
    words.push_back(word);
  }

  for(const auto &item : words){
    cout << item << endl;
  }
}
