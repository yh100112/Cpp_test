#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,int> um;

int main(){
  um["bts"] = 1;
  um["kfc"] = 2;
  um["bbq"] = 3;

  string str;
  cin >> str;

  if(um.count(str) > 0){
    cout << str << "가 1개 이상 해시맵에 존재한다.";
  }else{
    cout << "미발견";
  }
}