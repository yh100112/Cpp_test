#include <iostream>
#include <stdio.h>
using namespace std;

class config
{
public:
  static config& instance();

  void incr() {
    ++cnt;
  }

  int16_t cnt = 0;
};

config& config::instance()
{
    static config obj;
    return obj;
}

int main() {
  cout << config::instance().cnt << endl; // 0
  config::instance().incr();

  cout << config::instance().cnt << endl; // 1
  config::instance().incr();
  config::instance().incr();

  cout << config::instance().cnt << endl; // 3
}
