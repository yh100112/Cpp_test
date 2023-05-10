#include <iostream>
#include <stdio.h>
using namespace std;


class config
{
public:
  static config& instance() {
    static config obj; 
    printf("%p\n", &obj); 
    return obj;
  }

  void incr() {
    ++cnt;
  }

  int16_t cnt = 0;

};

int main() {
  cout << config::instance().cnt << endl;
  config::instance().incr();
  cout << config::instance().cnt << endl;
  config::instance().incr();
  config::instance().incr();
  cout << config::instance().cnt << endl;
}
