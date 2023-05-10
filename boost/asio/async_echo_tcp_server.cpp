#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<boost/bind.hpp>
#include<boost/asio.hpp>

using namespace std;

class Session
{
  private:
    boost::asio::ip::tcp::socket m_Socket;
    string m_WriteMessage;
    array<char, 128> m_ReceiveBuffer;
  public:
    Session(boost::asio::io_context& io_context)
      : m_Socket(io_context) {}

    boost::asio::ip::tcp::socket& Socket() {
      return m_Socket;
    }

    void PostReceive() {
      memset(&m_ReceiveBuffer, '\0', sizeof(m_ReceiveBuffer));

      m_Socket.async_read_some(boost::asio::buffer(m_ReceiveBuffer), boost::bind(&Session::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }

  private:
    void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/) {}

    void handle_receive(const boost::error_code& error, size_t bytes_transferred)
    {
      if(error) {
        if(error == boost::asio::error::eof)
          cout << "클라이언트와의 연결이 끊어졌습니다." << endl;
        else
          cout << "error no : " << error.value() << " error message : " << error.message() << endl;
      }
      else {
        const string strRecvMessage = m_ReceiveBuffer.data();
        cout << "클라이언트에서 받은 메시지 : " << strRecvMessage << ", 받은 크기 : " << bytes_transferred << endl;

        char szMessage[128] = {0,};
        sprintf_s(szNessage, 128 - 1, "Re:%s", strRecvMessage.c_str());
        m_WriteMessage = szMessage;

        boost::asio::async_write(m_Socket, boost::asio::buffer(m_WriteMessage), boost::bind(&Session::handle_write, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

        PostReceive();
      }
    }
};

const unsigned short PORT = 5555;

class TCP_Sever
{
private:
  int m_nSeqNumber;
  boost::asio::ip::tcp::acceptor m_acceptor;
  boost::asio::io_context& m_io_context;
  Session* m_pSession;

public:
  TCP_Server(boost::asio::io_service& io_service)
    : m_io_context(io_context), m_acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT))
  {
    m_pSession = nullptr;
    StartAccept();
  }

  ~Tcp_Server()
  {
    if(m_pSession != nullptr)
      delete m_pSession;
  }

private:
  void StartAccept()
  {
    cout << "클라이언트 접속 대기. . . . . " << endl;
    m_pSession = new Session(m_io_context);
    m_acceptor.async_accept(m_pSession->Socket(), boost::bind(&TCP_Server::handle_accept, this, m_pSession, boost::asio::placeholders::error));
  }

  void handle_accept(Session* pSession, const boost::system::error_code& error)
  {
    if(!error)
    {
      cout << "클라이언트 접속 성공" << endl;
      pSession->PostReceive();
    }
  }
};

int main()
{
  boost::asio::io_context io_context;
  TCP_Server server(io_context);
  io_context.run();

  cout << "네트웍 접속 좁료" << endl;

  return 0;
}
