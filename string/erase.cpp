#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "applebanana";
    a.erase(a.find("ba"),2);
    cout << a << endl; // "applenana"
}