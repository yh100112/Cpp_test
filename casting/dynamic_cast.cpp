#include <iostream>
#include <thread>
using namespace std;

class parent
{
public:
    parent(){}
    virtual void print(){
        cout << "parent" << endl;
    }
};

class child : public parent
{
public:
    child(){}
    virtual void print(){
        cout << "child" << endl;
    }
};

int main() {
    parent* p = new child();
    p->print();

    // child* c = p; // 컴파일 에러
    child* c = dynamic_cast<child*>(p);
    c->print();
    return 0;
}