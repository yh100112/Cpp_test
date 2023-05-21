#include<fstream>
#include<iostream>
using namespace std;

int main(){
  ofstream file("input.txt", file.out | file.app); 
  // 파일을 open()할 때 플래그(모드)를 직접 지정해줘서 뒤에 내용이 붙여넣어지게 함 ( file.app )
  // 두번째 인자를 주지 않고 open()하면 디폴트로 두번째 인자에 ios::out | ios::trunc가 들어가서 파일이 존재한다면 삭제하고 새로 만들게 된다.
  if(!file.is_open()){
    cout << "파일 오픈 실패" << endl;
  }else{
    file << "안녕!";
  }



}
