#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
  stringstream ss;
  ss << "3";
  ss << ",";
  ss << "4";

  string test = ss.str(); // stringstream을 string으로 바꿈

  cout << test << endl;
  cout << test.length() << endl;
}

