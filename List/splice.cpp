#include<iostream>
#include<list>
#include<functional>

using namespace std;

int main(){
    list<string> list1;
    list1.push_back("a");
    list1.push_back("b");
    list1.push_back("c");

    list<string> list2;
    list2.push_back("X");
    list2.push_back("Y");
    list2.push_back("Z");

    list2.splice(list2.begin(),list1);
    // list2에 list1을 갖다붙인다.
    // ->  list2.begin()이 가리키는 부분에 lt1을 잘라서 같다 붙인다. 
    //! lt1은 값이 사라짐

    list<string>::iterator iter;
    for(iter = list2.begin(); iter!= list2.end(); iter++) { cout <<*iter << " "; } // a b c X Y Z
}