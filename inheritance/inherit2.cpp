#include <iostream>

using namespace std;

class Mom
{
  protected:
    int a = 0;
    int b = 0;
  
  public:
    void add() {
      ++a;
      ++b;
    }
    
    void print() {
      cout << a << " " << b << endl;
    }
};

class Sun : public Mom
{
  private:
    int c = 0;
    int d = 0;
  public:
    void add() {
      c += 10;
      d += 10;
    }
    
    void print() {
      cout << c << " " << d << endl;
    }
};

int main() {
  Sun kdy;
  Mom ohs;

  ohs = kdy;
  ohs.add();   // 부모 add()
  ohs.print(); // 1, 1 -> 부모 print() 

  kdy.add();    // 자식 add()
  kdy.print();  // 10, 10 -> 자식 print()
}
