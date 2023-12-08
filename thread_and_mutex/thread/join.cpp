#include<iostream>
#include<thread>
using std::thread;

void func1(){
  for(int i = 0; i < 10; i++){
    std::cout << "쓰레드 1 작동중!\n";
  }
}

void func2(){
  for(int i = 0; i < 10; i++){
    std::cout << "쓰레드 2 작동중!\n";
  }
}

void func3(){
  for(int i = 0; i < 10; i++){
    std::cout << "쓰레드 3 작동중!\n";
  }
}

int main(){
  thread t1(func1);
  thread t2(func2);
  thread t3(func3);

  t1.join(); // t1이 종료되기 전까지 main()이 리턴하지 않음
  t2.join(); // t2가 종료되기 전까지 main()이 리턴하지 않음
  t3.join(); // t3가 종료되기 전까지 main()이 리턴하지 않음
  
  /*
  join을 쓰지 않으면 t1,t2,t3가 종료되기 전에 main이 종료된다.
  그래서 t1,t2,t3는 다 돌기도 전에 main이 종료되면 쓰레드 객체의 소멸자를 호출하고 종료된다.
  c++표준에 따르면, join되거나 detach되지 않는 쓰레드들의 소멸자가 호출된다면 예외를 
  발생시키도록 명시되어 있다.
  */
}


