#include<iostream>
#include<set>
using namespace std;

int main() {
  set<int16_t> s;
  s.insert(10);
  s.insert(10);
  s.insert(30);
  s.insert(20);

  for(auto& v: s)
    cout << v << endl; // 10 20 30

  if (s.find(10) != s.end())
    cout << *s.find(10) << endl; // 10
}
