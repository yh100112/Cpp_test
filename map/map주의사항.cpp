#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
using namespace std;

struct File{
  int a = 2;
  int b = 3;
  char* read_curr_ptr = (char*)&a;
};

int main(){
  map<int,struct File> m;
  struct File f;
  printf("%p %p\n", &f.a, f.read_curr_ptr);

  m[1] = f;
  /*
    객체 f의 복사본을 대입연산자로 m[1]의 value로 넣음 
    1. 복사본에서의 변수 a,b는 선언 당시 주소값을 대입한게 아닌 그냥 값을 대입한 것이므로 복사본에서도 문제가 되지 않음
    2. read_curr_ptr은 구조체 안에 있는 a의 주소값을 넣음. 그런데 복사본은 원래 구조체의 값들을 그대로 복사한 복사본이다. 
       !복사본에서의 read_curr_ptr은 처음 f를 만들 때의 a의 주소값을 그대로 복사한거라 복사본 구조체의 read_curr_ptr에는 복사본의 변수 a의 주소가 아닌 
       !구조체 객체 f를 처음 선언했던 당시의 원본 구조체 안에 있는 a의 주소값이 들어 있다.
  */
  printf("%p %p\n", &m[1].a, m[1].read_curr_ptr); 
}

/*
    옳은 방법
    m[1]; value로 구조체 File이 알아서 생성됨.
*/