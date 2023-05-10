#include<iostream>
#include<functional>

int multiple(int a, int b) {
  return a * b;
}

int multiple3and4() {
  return multiple(3, 4);
}

int multiple5and3() {
  return multiple(5, 3);
}

int main() {
  auto func1 = std::bind(&multiple, 3, 4);
  auto func2 = std::bind(&multiple, 5, 3);

  std::cout << multiple3and4() << " " << multiple5and3() << std::endl; // 기존방식 -> 매우 불편

  std::cout << func1() << " " << func2() << std::endl; // std::bind 사용 방식 ( 매우 편함 )
}
