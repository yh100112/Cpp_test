#include<iostream>
#include<functional>

int multiple(int a, int b) {
  return a * b;
}

int main() {
  std::function< int(void) > func1;
  func1 = std::bind(multiple, 10, 20); // 넣어주는 매개변수가 없이 10, 20이 default로 바인딩되어 있으므로 function<int(void)>에서 void로 매개변수를 받지 않는다.

  std::cout << "값 : " << func1() << std::endl; // 200

  std::function< int(int) > func3;  
  func3 = std::bind(multiple, 10, std::placeholders::_1);

  std::cout << "값 : " << func3(40) << std::endl; // 400
  // function< 반환타입(넣어줄 매개변수) >은 매개변수로 넣어줄 값이 1개면 1개, 2개면 2개 이렇게 지정해준다.
  // -> 여기서는 함수의 첫번째 매개변수는 bind에서 고정되어 있고 두번째 매개변수만 placeholders로 넣어줘야 하기 때문에 function을 만들 때 매개변수가 1개인 것이다.

  std::function< int(int, int) > func2;
  func2 = std::bind(multiple, std::placeholders::_1, std::placeholders::_2);

  std::cout << "값 : " << func2(30,40) << std::endl; // 1200

  return 0;
}

/*
function<반환타입(매개변수)>
- 매개변수 : 함수를 바인딩할 때 직접 입력하는 매개변수의 갯수에 따라 매개변수를 갯수만큼 설정해줘야 함
*/
