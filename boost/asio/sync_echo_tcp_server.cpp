#include<iostream>
#include<stdio.h>
#include<boost/asio.hpp>

using namespace std;

const unsigned short PORT = 5555;

int main() {
  boost::asio::io_context io_context; // boost asio의 핵심  -> 커널에서 발생한 IO 이벤트를 디스패치해준다. ( connect, accept, receive, send, . . . )

  boost::asio::ip::tcp::endpoint serv_addr(boost::asio::ip::tcp::v4(), PORT); 
  // 네트워크 주소를 설정한다. 이 주소로 클라이언트가 접속한다.
  // 서버는 스스로 자신의 ip주소를 알고 있기 때문에 따로 클라이언트처럼 ip주소를 넣어주는 작업을 하지 않는다. 
  // -> ip 주소체계만 넣어준다. ( ip::tcp::v4() 또는 ip::tcp::v6() )

  boost::asio::ip::tcp::acceptor acceptor(io_context, serv_addr); // 클라이언트 접속을 받아들이는 부분 -> serv_addr에 접속이 됐는지 알기 위해 serv_addr도 매개변수로 넘겨줌 

  boost::asio::ip::tcp::socket serv_sock(io_context); // 접속한 클라이언트에게 할당할 소켓을 만듬 -> 이 소켓을 통해 클라가 보낸 데이터를 주고받는다.

  acceptor.accept(serv_sock); // 클라이언트의 접속을 받아들인다.

  cout << "클라이언트 접속!" << endl;

  // 접속한 클라이언트가 있다면 서버를 무한으로 돌린다.
  for(;;)
  {
    char buf[128] = {0,};
    boost::system::error_code error;
    size_t len = serv_sock.read_some(boost::asio::buffer(buf), error); 
    // buffer형태로 buf배열에 클라가 보낸 데이터를 담는다. 동기 방식이므로 다 받을 때까지 대기상태로 있는다.
    // 만일 에러가 발생한다면 error에 에러 정보가 담긴다.
    
    if(error)
    {
      if(error == boost::asio::error::eof)
        cout << "클라이언트와 연결이 끊어졌습니다." << endl;
      else
        cout << "error No : " << error.value() << " error Message : " << error.message() << endl;
      
      break;
    }
    
    cout << "클라이언트에서 받은 메세지 : " << buf << endl;
    char send_msg[128] = {0,};
    sprintf(send_msg, "응답:%s", buf); // 서버에서 입력받아 클라에 보낼 문자
    
    boost::system::error_code ignored_error;
    serv_sock.write_some(boost::asio::buffer(send_msg, 128 - 1), ignored_error); // send_msg에 담긴 데이터를 127만큼만 클라에게 보낸다.
  }
}
