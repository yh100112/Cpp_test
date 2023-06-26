#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(108);
    lt.push_back(120);
    lt.push_back(60);
    lt.push_back(10);

    list<int>::iterator iter;

    lt.remove_if([] (int num) { return num >= 100 && num <= 200; }); // remove_if() 후 lt : 10 20 60 10
    lt.remove(10); // remove_if() 후 lt : 20 60
}