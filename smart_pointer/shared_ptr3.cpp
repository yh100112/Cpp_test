#include<iostream>
#include<memory>
using namespace std;

class Person
{
public:
  Person(){
    cout << "생서자 호출" << endl;
  }

  ~Person(){
    cout << "소멸자 호출" << endl;
  }
};

int main(){
  shared_ptr<Person> p = make_shared<Person>();
}
