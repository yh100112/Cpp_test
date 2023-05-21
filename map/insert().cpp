#include<map>
#include<iostream>
using namespace std;

int main() {
  map<int, string> temp;
  pair<map<int, string>::iterator, bool> ret = temp.insert({1, "number 1"});
  // ret.first : insert할 위치(iterator)
  // ret.second : insert성공 여부 ( true, false )

  if (!ret.second) {
    ret.first->second = "number 1";
  }
  else {
    cout << ret.first->second << endl; // number 1
  }
}

// std::map 의 insert()의 반환값 : pair<iterator, bool> 이다. 
// ! 주의사항 : map은 <key, value> 형태라서 ret.first의 형태는 map<int, string>::iterator이다.
