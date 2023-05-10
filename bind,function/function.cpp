#include<iostream>
#include<functional>

class Cclass;

// final : 상속 불가한 클래스
class Cclass final {
public:
  Cclass () {}
  ~Cclass() {}
  
  void func() { std::cout << "wow! this is function!" << std::endl; }
  void funcFloat(float x, float y) { std::cout << "x : " << x << ", y : " << y << std::endl; }
  int funcReturnInt() { return 100; }
};

int main() {
 Cclass _class;

 std::function<void()>             func1 = std::bind(&Cclass::func, &_class); 
 std::function<void(float, float)> func3 = std::bind(&Cclass::funcFloat, &_class, std::placeholders::_1, std::placeholders::_2);
 std::function<int()>              func4 = std::bind(&Cclass::funcReturnInt, &_class);
 std::function<void(int)> funcLamda = [](int _num) {
   std::cout << "Input Number = " << _num << std::endl;
 };

 func1();
 func3(15.0f, 20.0f);
 std::cout << "return number is : " << func4() << std::endl;
 funcLamda(20.0f);
}

/*
 function에 bind()로 함수를 바인딩할 때 bind()의 매개변수 설정
 - 첫번쩨 메개변수 : 함수 참조(&)
 - 두번째 매개변수 : 함수를 멤버함수로 가지고 있는 인스턴스(_class) 객체를 두번째 매개변수로 꼭 넣어줘야 함 !!!!!!!! ( 중요 )
*/
