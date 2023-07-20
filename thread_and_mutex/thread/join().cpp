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
}


