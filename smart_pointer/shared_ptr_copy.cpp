#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int> s1 = make_shared<int>(10);
    
    shared_ptr<int> s2 = s1;
    *s2 = 2;

    cout << *s1 << endl; // 2
    cout << *s2 << endl; // 2
}

// shared_ptr도 포인터이므로 복사본의 데이터를 바꾸면 원본의 데이터도 바뀐다.



