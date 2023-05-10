#include<iostream>
using namespace std;

class A{
  private:
    int a_;
    int b_;

  public:
    A(int a, int b){
      a_ = a;
      b_ = b;
    }

    int add(){
      return a_ + b_;
    }
};

class B : A {
  public:
    B(int a_, int b_) : A(a_, b_){} 
    /* 
    부모 클래스의 초기화를 하는 방법 => 부모클래스명(매개변수1, 매개변수2. . .)
    B는 A를 상속받아서 a_와 b_는 갖고 있지만 접근할 수는 없다.
    하지만 add()함수는 public으로 접근할 수 있기 때문에 add()로 결과값을 출력한다.
    */

    void printResult(){
      //A를 상속받았으니, 부모클래스의 add라는 메소드를 사용할 수 있음.
      printf("%d\n", add());
    }
};

int main(){
  B b(1,2);
  b.printResult();
}
