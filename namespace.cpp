#include<iostream>
#include<string>
using namespace std;

namespace A{
  int test = 2;
  void hello(){
    cout << "I am A" << endl;
  }
}

namespace B{
  void hello(){
    cout << "I am B" << endl;
  }
}

int main(){
  A::hello();
  B::hello();
  cout << A::test << endl;
}
