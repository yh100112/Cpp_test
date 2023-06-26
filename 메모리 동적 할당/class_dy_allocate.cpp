#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class Pony
{
private:
  string memoryLocation;
  string num;
public:
  Pony(string str) {
    this->num = str;
  };
  ~Pony(){};
  void setNum(string str){ num = str;}
  string getNum(){
    return num;
  }
};

int main(){
  Pony* heapPony = new Pony("First"); // class dynamic allocate
  cout << heapPony->getNum() << endl;
  delete heapPony;
  /*
    new    : 메모리할당, 생성자 호출, 타입변환 총 세가지 일을 함
    delete : 소멸자를 자동으로 호출하고 메모리를 해제
  */
}