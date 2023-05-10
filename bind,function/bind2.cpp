#include<iostream>
#include<functional>

int multiple(int a, int b) {
  return a * b;
}

int main() {
  int a = 10;
  int b = 20;
  auto func1 = std::bind(&multiple, a, b);
  std::cout << "값1 : " << func1() << std::endl; // 200

  a = 2;
  b = 3;
  std::cout << "값2 : " << func1() << std::endl; 
  // 그대로 200 -> bind는 호출되는 시점의 변수값으로 바인딩하기 때문에 이후에 변수값을 바꿔도 영향 x
  // 바인딩할 때 std::cref(a), std::cref(b) 이렇게 하면 나중에 변수값을 바꾸면 바인딩된 값도 바뀌게 된다.

  return 0;
}
