#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person{
  char name[20];
  int age;
  char address[100];
};

int main(){
  struct Person *p1 = (struct Person*)malloc(sizeof(struct Person));

  strcpy(p1->name,"ggg");
  p1->age = 30;
  strcpy(p1->address,"방배동");
  
  printf("%s, %d, %s\n", p1->name, p1->age, p1->address);

  free(p1);
}
/*
  보통 구조체는 멤버 변수가 여러개 들어있어 크기가 큰 편이다.
  그래서 구조체 변수를 일일이 선언해서 사용하는 것보단 동적할당해서 사용하는 편이 효율적이다.
*/
