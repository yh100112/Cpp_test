#include<iostream>
#include<string.h>
using namespace std;

class A{
private:
  char* name;
public:
    A(const char* myname){
        name = new char[strlen(myname) + 1];
        strcpy(name,myname);
    }

    // 복사생성자 직접 생성
    A(const A& copy){
        name = new char[strlen(copy.name) + 1];
        strcpy(name,copy.name);
    }

    void showInfo() const{
        cout << "이름 : " << name << endl;
    }

    ~A(){
        delete []name;
        cout << "소멸자 호출" << endl;
    }
};

int main(){
  A a("deokyong");
  A b = a;
  a.showInfo();
  b.showInfo();

  return 0;
}