#include<bits/stdc++.h>
using namespace std;

struct Ralo {
    int a,b;
    double c,d,e;
};

void print(Ralo ralo) {
    cout << ralo.a << " " << ralo.b << " " << ralo.c << " " << ralo.d << " " << ralo.e << "\n";
}

int main() {
    Ralo ralo = {1,1,1,1,1};
    print(ralo); // 1 1 1 1 1

    vector<Ralo> ret;
    ret.push_back({1,2,3,4,5});
    ret.push_back({1,2,3,4,6});
    ret.push_back({});
    ret.push_back({1,3});

    for(Ralo ralo : ret) {
        print(ralo);
    }
    /*
    1 2 3 4 5
    1 2 3 4 6
    0 0 0 0 0
    1 3 0 0 0
    */
}

/*
구조체는 c++에서 제공하는 자료구조가 아닌 개발자가 커스텀하게 만들 수 있는 자료구조를 의미한다.

커스텀한 자료구조를 만들 때 보통 class or struct를 쓴다.

struct vs class
- struct의 멤버변수는 기본적으로 public으고 상속이 안됨
- class의 멤버변수는 기본적으로 private이며 상속이 됨
*/