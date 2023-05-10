#include<iostream>
#include<string>
using namespace std;

class Person
{
  private:
    int age_;
    string str_;

  public:
    Person() : age_(0), str_("kdy")
    {
      cout << "디폴트 생성자 호출" << endl;
    }
    
    Person(int age, string str) : age_(age), str_(str)
    {
      cout << "age, str 생성자 호출" << endl;
    }
    
    Person& operator = (const Person& rsh)
    {
      this->age_ = rsh.age_;
      this->str_ = rsh.str_;
      cout << "대입연산자 호출" << endl;
      return *this;
    }
    
    void printAll(){
      cout << "age : " << age_ << endl;
      cout << "str : " << str_ << endl;
    }
};

int main(){
  cout << "=====" << endl;
  Person p1(10, "aa"); // age, str 생성자 호출
  p1.printAll();
  
  cout << "\n=====\n";
  Person p2 = {20, "bb"}; // age, str 생성자 호출
  p2.printAll();
  
  cout << "\n=====\n";
  Person p3 = Person(30, "cc"); // age, str 생성자 호출
  p3.printAll();
  
  cout << "\n=====\n";
  Person p4; // 디폴트 생성자 호출
  p4 = Person(40, "dd"); // age, str 생성자 호출 후 대입연산자 호출
  p4.printAll();
  
  return 0;
}
