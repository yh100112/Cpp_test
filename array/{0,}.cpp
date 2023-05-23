#include<bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    int a[5] = {0, };
    while(++cnt != 10) {
        for (int i = 0; i < 5; i++) a[i] = i;
        a[5] = {0,}; // 여기서 0으로 초기화되지 않음
        for(int i : a)
            cout << i << ' ';
        cnt++;
    }
}

/*
위 초기화 방법은 초반에 한번 하는 정적 초기화로써만 유효하다.
동적초기화로써는 작동하지 않는다.
*/