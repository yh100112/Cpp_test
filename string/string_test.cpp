#include<bits/stdc++.h>
using namespace std;

int main() {
    string a = "a";
    string b = "b";
    cout << a + b << endl; // ab
    a += b;
    cout << a << endl; // ab

    string s[3] = {"apple", "banana", "grapes"};
    string joinStr = "";
    for(auto i : s) {
        joinStr += i + "-";
    }
    cout << joinStr << endl;


    string c = "c";
    c += "d";
    cout << c << endl; // cd

    // cout << "a" + "b" << endl; // 컴파일 에러 -> 문자 배열 두개를 단순히 더하는 것은 불가능!

    string d = "hello world!";
    cout << d.find("ell") << endl; // 1
    cout << d.substr(7) << endl; // orld!
    cout << d.substr(7, 3) << endl; // orl


}