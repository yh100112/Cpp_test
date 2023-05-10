#include<iostream>
#include<boost/format.hpp>
using namespace std;

int main ()
{

  // %1% : 첫번째 인자("hello") , %2% : 두번째 인자(100)
  cout << boost::format("%1% %2%") % "hello" % 100 << endl; // hello 100

  // %2% %1% 역순으로 사용 가능
  cout << boost::format("%2% %1%") % "hello" % 100 << endl; // 100 hello

  // printf() 형식처럼 사용 가능
  // %x : 16진수
  // %f : float형
  // %% : % 출력
  cout << boost::format("%05d %x %f %%") % 200 % 255 % 3.33 << endl; // 00200 ff 3.330000 %

  // %숫자$[입력포맷] : 순서지정과 출력형식 printf처럼 지정을 동시에 하는 것
  // %04x : 4자리 16진수 => fe이면 00fe로 출력
  // %s : 문자열
  cout << boost::format("%2$04x %1$s") % "hello" % 254 << endl; // oofe hello


  // - : 왼쪽 정렬
  cout << boost::format("%-05d,%-10f,%d") % 200 % 3.33 % 20000 << endl; 

  // -  없으면 디폴트로 오른쪽 정렬 
  cout << boost::format("%5d") % 10 << endl; 

  // 5자리 오른쪽 정렬인데 숫자가 없는 곳은 0으로 채움 => 10이면 00010 출력
  cout << boost::format("%05d") % 10 << endl; 

  // + : 양수여도 부호 표시함
  cout << boost::format("%+5d") % 10 << endl;  //  +10 => 총 5자리 오른쪽 정렬인데 양수이면 +를 붙여서 출력 

  // 10칸 오른쪽 정렬인데 소숫점 밑자리 5자리까지 출력
  cout << boost::format("%10.5f,%d") % 3.33 % 5 << endl;
  

}
