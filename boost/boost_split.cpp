#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>
using namespace std;

int main() {
  vector<string> dd;
  string a = "1 2 3 4 5";
  // boost::split(dd, a, " "); -> error
  // boost::split(dd, a, boost::is_any_of(" ")); // ' '으로 하면 에러남
  boost::split(dd, a, [](char c) {return c == ' ';}); 

  for(auto& v : dd)
    cout << v << endl;

}
