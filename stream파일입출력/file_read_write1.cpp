#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(){
  vector<string> words = {"blockdmask" ,"banana", "code", "program"};
  int len = static_cast<int>(words.size());

  //ifstream readFromFile;
  //readFromFile.open("words.txt");  -> 이 두줄을 한번에 작성하는 법
  ifstream readFromFile("words.txt");

  if(readFromFile.is_open()){ // words.txt가 있으면
    words.clear();
    while(!readFromFile.eof()){ // readFromFile의 끝이 아니라면
      string tmp;
      getline(readFromFile, tmp);
      words.push_back(tmp);
    }
    readFromFile.close();
  }
  else{ // words.txt가 없으면
    ofstream writeToFile("words.txt"); // output stream으로 파일 생성! -> ofstream은 파일이 없다면 생성해줌

    for(int i=0; i<len; ++i){
      string tmp = words[i];
      cout << tmp.size() << endl; // 10 6 4 7
      if(i != len - 1){
        tmp += "\n";  // 마지막 단어 빼고 엔터 넣어주기
      }

      writeToFile.write(tmp.c_str(), tmp.size()); // c_str() : string -> char*
    }
    writeToFile.close();
  }
}
