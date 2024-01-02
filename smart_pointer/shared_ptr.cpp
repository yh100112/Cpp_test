#include<iostream>
#include<memory> // shared_ptr header file

using namespace std;

int main(){
    shared_ptr<int> ptr01(new int(5));  // int형 shared_ptr인 ptr01을 선언하고 초기화함 -> 동적할당
    cout << ptr01.use_count() << endl;

    auto ptr02(ptr01);
    cout << ptr02.use_count() << endl;

    auto ptr03 = ptr01;
    cout << ptr02.use_count() << endl;

    printf("%p %p %p\n", &ptr01, &ptr02, &ptr03);
    cout << *ptr01 << endl;
    cout << *ptr03 << endl;
}
// main{} 블록이 끝나면 알아서 동적할당된 ptr01,ptr02,ptr03 을 delete로 해제해준다. ( shared_ptr이기 때문에)
