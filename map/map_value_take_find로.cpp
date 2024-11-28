#include<iostream>
#include<map>
using namespace std;

int main()
{
  map<int, string> m;
  m.insert({1, "aa"});
  m.insert({2, "bb"});
  m.insert({3, "cc"});

  cout << m.find(1)->second << endl; // [] 를 사용하지 않고 map의 value 가져오기
}
