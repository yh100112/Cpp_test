#include <iostream>
using namespace std;
class Parent
{
public:
  virtual void func1() { cout << "이곳은 parent의 func1입니다." << endl; }
  virtual void func2() { cout << "이곳은 parent의 func2입니다." << endl; } // 자식에서 재정의하면 자식에 있는 오버라이딩된 func2()를 호출할 수 있도록 해줌 ( virtual로 인해 )
  void func3() { cout << "이곳은 parent의 func3입니다." << endl; } // 이건 오버라이딩 해도 c->func3()하면 부모의 func3()이 호출됨
  virtual void func4() = 0; // 무조건 자식에서 정의해줘야 하는 함수
};
// 부모에서 virtual로 선언된 것은 자식에서 무조건 재정의해줘야함 ( java의 abstract와 같은 기능 )

class Child : public Parent
{
public:
  void func2() { cout << "이곳은 child의 func2입니다." << endl; }
  void func3() { cout << "이곳은 child의 func3입니다." << endl; }
  void func4() { cout << "이곳은 child의 func4입니다." << endl; }
};

int main()
{
  Parent *c = new Child;
  c->func1(); // parent -> 부모에 func1이 있고, 자식에 오버라이딩한 func1이 없으므로 부모의 func1() 호출
  c->func2(); // child  -> 부모에 있는데 virtual이므로 자식의 오버라이딩 된 func3() 호출
  c->func3(); // parent -> 부모에 있는데 virtual이 아니므로 자식에 오버라이딩된 게 아닌 부모의 func3()을 호출
  c->func4(); // child  -> 부모에 없으므로 자식으로 내려온다.
}