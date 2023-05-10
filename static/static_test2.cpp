#include <iostream>
using namespace std;

class config
{
  public:
    static int16_t b;
    int16_t returnA() {
      static int a;
      ++a;
      return a;
    }
};

int16_t config::b = 1; // 초기화 꼭 해줘야 함

int main() {
  config con;
  cout << con.returnA() << endl; // 1
  cout << con.returnA() << endl; // 2
  cout << con.returnA() << endl; // 3
  cout << con.returnA() << endl; // 4

  cout << con.b << endl; // 1
  con.b = 2;
  cout << con.b << endl; // 2


  // config config2;
  // cout << config2.returnA() << endl;
  // cout << config2.returnA() << endl;
  // cout << config2.returnA() << endl;
}
