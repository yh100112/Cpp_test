#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream input;
  input.open("input.txt");

  if(input.fail()){
    cout << "파일을 여는데 실패했습니다." << endl;
  }

  input.seekg(0, input.end);
  cout << "파일의 길이는 " << input.tellg() << "입니다. " << endl; //전체 글자  + 맨 뒤에 '\0' 1개
  input.seekg(0,input.beg); // 다시 offset을 처음으로 돌려놓음
  input.close();

  // -----------------------------------------------------------------------

  ifstream file("input.txt", file.in | file.binary ); // 파일크기를 바이너리로 읽기 위해 플래그 설정

  // 파일의 크기 : byte 구하기
  long l,m;
  l = file.tellg(); // 파일 제일 앞 offset 위치 가져옴
  file.seekg(0, file.end); // 파일 offset을 맨 뒤로 보냄
  m = file.tellg(); // 맨 뒤로 간 offset 위치 가져옴

  file.close();

  cout << "파일의 크기는 " << m - l << "byte입니다." << endl; // .txt파일에 쓴 건 모두 문자이기 때문에 바이트로 계산해도 파일 길이랑 똑같이 나온다.
}
