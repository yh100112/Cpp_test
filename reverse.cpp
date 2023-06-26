#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcde";
    cout << *(s.begin() + 4) << endl; // e
    reverse(s.begin() + 0,s.begin() + 5);
    cout << s << endl;
}