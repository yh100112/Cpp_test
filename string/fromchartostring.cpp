#include<bits/stdc++.h>
using namespace std;

int main(){
    char code = '1';
    char code2 = '3';
    string ret = "";
    ret += code;
    ret += string(1, code2);
    cout << ret << endl;

    // char 그대로 string에 더해주는 거나 char를 string으로 바꿔서 더해주는 거나 둘 다 가능
}