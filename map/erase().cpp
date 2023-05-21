#include<map>
#include<iostream>

using namespace std;

int main(){
    map<string,int> m;
    m.erase("scv");
    m.erase(m.find("firebat"));
}