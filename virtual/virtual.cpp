#include <iostream>
using namespace std;
class Parent
{
public:
  virtual void func1() { cout << "이곳은 parent의 func1입니다." << endl; }
  virtual void func2() { cout << "이곳은 parent의 func2입니다." << endl; }
  void func3() { cout << "이곳은 parent의 func3입니다." << endl; }
};
// 부모에서 virtual로 선언된 것은 자식에서 무조건 재정의해줘야함 ( java의 abstract와 같은 기능 )

class Child : public Parent
{
public:
  void func1() { cout << "이곳은 child의 func1입니다." << endl; }
  void func2() { cout << "이곳은 child의 func2입니다." << endl; }
  void func3() { cout << "이곳은 child의 func3입니다." << endl; }
};

int main()
{
  Parent *c = new Child;
  c->func1(); // child
  c->func2(); // child
  c->func3(); // parent
}