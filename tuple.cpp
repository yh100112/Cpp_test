#include<iostream>
#include<string>
#include<tuple>
using namespace std;

tuple<int, string> getName()
{
  int age;
  string name;
  cout << "나이 : ";
  cin >> age;

  cout << "이름 : ";
  cin >> name;

  return make_tuple(age, name);
}

int main() {
  tuple<int, string> personInfo;
  personInfo = getName();

  cout << "나이 : " << get<0>(personInfo) << endl;
  cout << "이름 : " << get<1>(personInfo) << endl;
}
