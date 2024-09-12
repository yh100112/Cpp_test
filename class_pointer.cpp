#include<iostream>
using namespace std;

class Test {
public:
  void print() {
    std::cout << "hello" << std::endl;
  }
};

int main() {
  Test* t;  // 포인터만 선언 (객체는 생성되지 않음)
  t->print();  // 문제 발생: t는 초기화되지 않은 포인터

  // 하지만 컴파일 한 후 실행하면 문제 없이 hello가 출력되는데, 이건 운이 좋게 된 것이지, t는 정의되지 않았으므로 예기치 못한 문제가 발생할 수 있다.
}
