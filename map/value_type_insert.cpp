#include<map>
#include<iostream>

using namespace std;

int main() {
  std::map<int, string> temp;

  auto ret = temp.insert(std::map<int, string>::value_type(1, "numberOne"));
  cout << ret.first->first << " " << ret.first->second << endl;
}
