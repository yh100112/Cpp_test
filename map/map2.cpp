#include<map>
#include<iostream>

using namespace std;

int main() {
  std::map<int, std::string> temp;

  auto ret = temp.insert({1, "number1"});
  cout << ret.first->first << " " << ret.first->second << endl; // 1 number1
}
