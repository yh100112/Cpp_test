#include<bits/stdc++.h>
using namespace std;

class Parent {
  void print() {
    cout << "mom" << endl;
  }
};

class Child : Parent {
  void print() {
    cout << "Sun" << endl;
  }
};

int main() {
  Parent p;
  p.print();
}