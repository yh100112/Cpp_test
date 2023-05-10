#include <iostream>

extern int a;  // OK

int main()
{
  using namespace std;

  cout << a << endl;
}
