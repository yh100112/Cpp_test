#include<map>
#include<iostream>

using namespace std;

int main() {
  std::map<int, std::string> temp;
  auto ret = temp.insert({1, "number 1"});
  if (!ret.second) {
    ret.first->second = "number 1";  // ret.first : insert할 위치의 iterator
  }
}

/*
 *
 * std::map 의 insert()의 반환값은 pair<iterator, bool> 이다. 
