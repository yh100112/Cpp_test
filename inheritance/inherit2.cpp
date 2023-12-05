#include <iostream>

using namespace std;

class Mom
{
protected:
    int a = 0;
    int b = 0;
public:
    void add() { ++a, ++b; }
    void print() { cout << a << " " << b << endl; }
};

class Sun : public Mom
{
private:
    int c = 0;
    int d = 0;
public:
    void add() { c += 10, d += 10; }
    void momAdd() { a += 20, b += 20; }
    void print() { cout << c << " " << d << endl; }
    void print2() { cout << a << " " << b << endl; }
};

int main() {
  Sun kdy;
  Mom ohs;

  ohs = kdy;
  ohs.add();   // 부모 add()
  ohs.print(); // 1, 1 -> 부모 print() 

  kdy.add();    // 자식 add()
  kdy.momAdd(); // 부모의 a,b는 protected로 자식에서는 접근 가능하도록 되어 있기 때문에 가능
  kdy.print();  // 10, 10 -> 자식 print()
  kdy.print2(); // 20, 20
}
