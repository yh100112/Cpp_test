#include<iostream>
#include<memory>
using namespace std;
class Person
{
private:
  string name_;
  int age_;
public:
  Person(const string &name, int age);
  ~Person(){}
  void ShowPersonInfo();
};

Person::Person(const string &name, int age){
  name_ = name;
  age_ = age;
  cout << "생성자 호출" << endl;
}

void Person::ShowPersonInfo(){
  cout << name_ <<"의 나이는 " << age_ << "살입니다." << endl;
}

int main(){
  Person *a1 = new Person("zzzz",33);
  shared_ptr<Person> pp = shared_ptr<Person>(a1); // a1이 동적할당, 즉 포인터가 아니라면 이렇게 넣을 수 없음

  shared_ptr<Person> hong = make_shared<Person>("길동",29);
  hong->ShowPersonInfo();
  cout << hong.use_count() << endl;
}
/*
    Person객체를 가리키는 shared_ptr 인스턴스인 hong은 일반 포인터와는 달리 사용이 끝난 후
    delete키워드를 사용하여 메모리를 해제할 필요가 없다.
*/