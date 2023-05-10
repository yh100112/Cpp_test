#include<iostream>
#include<boost/asio.hpp>
#include<boost/bind/bind.hpp>

class printer
{
  private:
    boost::asio::steady_timer timer_;
    int count_;
  public:
    printer(boost::asio::io_context& io)
      : timer_(io, boost::asio::chrono::seconds(1)), count_(0)
    {
      timer_.async_wait(boost::bind(&printer::print, this)); // class에 접근하는 것이므로 bind 첫번째 매개변수로 객체를 꼭 넣어줘야 함!!
    }

    ~printer()
    {
      std::cout << "final count is " << count_ << std::endl;
    }

    void print() {
      if(count_ < 5)
      {
        std::cout << count_ << std::endl;
        ++count_;

        timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
        timer_.async_wait(boost::bind(&printer::print, this));
      }
    }
};

int main() {
  boost::asio::io_context io;
  printer p(io);
  io.run();

  return 0;
}
