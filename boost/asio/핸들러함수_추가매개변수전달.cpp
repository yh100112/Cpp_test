#include<iostream>
#include<boost/asio.hpp>
#include<boost/bind/bind.hpp>

/*
 * timer가 1초에 1번 수행되도록 구현
 * -> 반복 타이머를 구현하려면 완료 핸들러(콜백)에서 타이머 만료 시간을 변경하고 새로운 비동기 대기작업을 시작해야 한다.
 *    그러기 위해서는 async_timer.cpp의 print()에 두 개의 매개변수를 추가한다.
 *    1. 타이머 객체에 대한 포인터
 *    2. 타이머가 여섯번째로 작동할 때 프로그램을 중지할 수 있도록 하는 카운터
 */

void print(const boost::system::error_code& e, boost::asio::steady_timer* t, int* count) {
  if (*count < 5)
  {
    std::cout << *count << std::endl;
    ++(*count);
    
    t->expires_at(t->expiry() + boost::asio::chrono::seconds(1)); // 타이머의 만료시간 = 이전 만료시간 + 1
    t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count)); 
    // 새로운 비동기 대기작업 시작 ->  bind()로 추가매개변수를 완료 핸들러(callback함수)에 전달
    // boost::asio::placeholders::error : 핸들러에 전달된 오류 객체에 대한 자리 표시자

  }
}

int main(){
  boost::asio::io_context io;
  int count = 0;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
  t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));

  io.run(); // 완료 핸들러(callback함수) print()가 종료되면 더 이상 할 일이 없으므로 run()이 블록에서 해제되고 리턴된다.

  std::cout << "final count is " << count << std::endl;

  return 0;
}
