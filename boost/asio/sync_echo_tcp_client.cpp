#include <boost/asio/io_context.hpp>
#include <boost/system/error_code.hpp>
#include<iostream>
#include<boost/asio.hpp>

using namespace std;

const char server_ip[] = "127.0.0.1";
const unsigned short PORT = 5555;

int main() {
  boost::asio::io_context io_context; // boost asio의 핵심 -> 커널에서 발생한 IO 이벤트를 디스패치해준다. ( connect, accept, receive, send, . . . )
  boost::system::error_code connect_error;

  boost::asio::ip::tcp::endpoint serv_addr(boost::asio::ip::address::from_string(server_ip), PORT);
  // 접속할 서버의 ip, port정보를 입력
  // 서버는 ip주소체계를 입력하지만 클라는 접속할 서버 주소를 인자로 입력한다.
  // boost::asio::ip::address::from_string 클래스를 사용하여 문자열로 된 ip주소를 boost::asio에서 사용하는 ip주소 형태로 변환한다.

  boost::asio::ip::tcp::socket clnt_sock(io_context); // client 소켓 생성

  clnt_sock.connect(serv_addr, connect_error); // 서버에 접속 시도 -> 동기 방식이므로 접속이 성공하거나 실패할 때까지 대기한다.

  if(connect_error) {
    cout << "연결 실패. error no : " << connect_error.value() << ", message : " << connect_error.message() << endl;
    return 0;
  }
  else
    cout << "서버에 연결 성공!" << endl;

  // 서버에 메시지를 7번 보내고 연결 종료할 거임
  for (int i = 0; i < 7; i++) {
    // char szMessage[128] = {0, };
    string szMessage;
    cout << "입력 : ";
    // cin >> szMessage;
    getline(cin, szMessage);
    boost::system::error_code write_error;
    
    clnt_sock.write_some(boost::asio::buffer(szMessage, szMessage.size()), write_error); // server에 데이터 전송
    cout << "서버에 보낸 메세지 : " << szMessage << endl;

    char buf[128] = {0,};
    boost::system::error_code error;
    size_t len = clnt_sock.read_some(boost::asio::buffer(buf), error); // 서버에서 데이터 받음

    if(error)
    {
      if(error == boost::asio::error::eof) // error가 eof라면 서버와 연결 끊어진 거임
        cout << "서버와 연결이 끊어졌습니다." << endl;
      else
        cout << "error No : " << error.value() << " error Message : " << error.message().c_str() << endl;
      break;
    }

    cout << "서버로부터 받은 메세지 : " << buf << endl;
  }

  if(clnt_sock.is_open())
    clnt_sock.close();

  return 0;
}
