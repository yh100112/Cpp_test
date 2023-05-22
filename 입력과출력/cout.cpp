#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a = 1.23456789;

int main() {
    cout << a << "\n"; // 1.23457
    cout.precision(7); // 소숫점 포함 7개까지 나오게 함
    cout << a << "\n"; // 1.234568
}