#include<iostream>
#include<boost/asio.hpp>

// 비동기 대기가 완료될 때 호출되는 완료 핸들러 함수 -> callback함수
// 커널에서 어플이 호출한 이 함수를 완료시키고, 어플은 안 기다리고 다른 거 함
void print(const boost::system::error_code& e)
{
  std::cout << "hello" << std::endl;
}

int main()
{
  boost::asio::io_context io;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  //비동기 대기를 수행하기 위해 steady_timer::async_wait() 호출
  t.async_wait(&print);

  //비동기 작업을 할 때 완료 핸들러(callback함수)는 현재 io_context::run()을 호출하는 스레드에서만 호출된다.
  //-> run()이 호출되지 않으면 비동기 대기 완료에 대한 완료 핸들러가 호출되지 않는다.
  // run()함수는 수행할 작업이 있는 동안에도 계속 실행된다.
  // 이 예시에서 작업 :  타이머에 대한 비동기식 대기이므로 타이머가 만료되고 완료 핸들러가 반환될 때까지 run()은 반환하지 않는다.
  // 만약 io_run()을 호출하기 전에 async_wait()을 하지 않았다면, 즉 io_context는 할 작업이 없을 것이고 그렇다면 run()은 즉시 반환되었을 것이다.
  // -> run()을 호출하기 전에 꼭 수행할 작업을 써줘야 한다!!
  io.run();

  return 0;
}

/*
 * async 방식-> 함수 실행이 잘 됐다!에 대한 결과가 아니라 함수 실행했다! 에 대한 결과를 바로 return
