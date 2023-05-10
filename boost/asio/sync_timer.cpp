#include<iostream>
#include<boost/asio.hpp>

//compile 할 때 -pthread 입력해야함
int main(){
  boost::asio::io_context io;

  // I/O  or timer 작업을 하는 asio에서 제공하는 함수들은 모두 공통적으로 첫번째 인자에 boost::asio::io_context 가 들어간다.
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5)); // 5초 후에 타이머가 종료됨

  t.wait(); // 5초 동안 block되어 있다가 5초가 지나면 리턴함

  std::cout << "hello" << std::endl;
  return 0;
}
