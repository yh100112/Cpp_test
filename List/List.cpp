#include<list>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    list<char> list1;
    list1.push_back('c');
    list1.push_back('b');
    list1.push_back('a'); // push_back()을 한 후 iterator는 넣은 값 다음 위치를 가리키고 있다.
    
    list<char>::iterator itor = list1.begin();
    while(itor != list1.end()){
        cout << *itor << endl;
        itor++;
    }
    
    // 찾아낸 값의 앞에 d를 집어넣기. 없으면 맨 뒤에 들어감
    itor = find(list1.begin(),list1.end(),'a');
    list1.insert(itor,'d');

    //b삭제
    itor = find(list1.begin(),list1.end(),'b');
    list1.erase(itor);

    //특정 인덱스 위치에 값을 넣는 방법
    int i=0;
    int index = 2;
    for(itor = list1.begin(); itor != list1.end(); itor++,i++){
        if(i == index) break;
    }
    list1.insert(itor,'f');
}