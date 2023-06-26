#include<bits/stdc++.h>
using namespace std;
int a = 1, b = 2;
double p = 1.23456789;
int c = 12, d = 2;

int main() {
    printf("홍철 %d : 지수 %d\n", a, b);

    printf("%.6lf\n", p); // 1.234568
    printf("%03d\n", c); // 012
    printf("%02d\n", d); // 02
}

// 형식을 지정해서 출력할 때 좋음
// 예를 들어 "홍철 1 : 지수 2" 이런 형식으로 출력하라고 한다면 printf로 형식을 지정해서 출력해주면 좋음
// 예를 들어 소수점 6자리까지, 2를 02로 출력하라고 한다면 형식을 지정해서 출력해주면 좋음