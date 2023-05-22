#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "1";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << "\n"; // 1
    cout << atoi(s2.c_str()) << "\n"; // 0
}

/*
문자열을 int로 바꿈
문자열이 문자라면 -> 0 반환
문자열이 숫자라면 -> 숫자 반환
*/
