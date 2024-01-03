#include <iostream>
#include <memory>
#include <string>
using namespace std;

class B;
class C;

class A {
private:
    shared_ptr<B> b_;
    shared_ptr<C> c_;
public:
    A() {cout << "A 생성자 호출" << endl;}
    ~A() {cout << "A 소멸자 호출" << endl;}
    void set_b(shared_ptr<B> b) {b_ = b;}
    void set_c(shared_ptr<C> c) {c_ = c;}
};

class B {
private:
    shared_ptr<A> a_;
    shared_ptr<C> c_;
public:
    B() {cout << "B 생성자 호출" << endl;}
    ~B() {cout << "B 소멸자 호출" << endl;}
    void set_a(shared_ptr<A> a) {a_ = a;}
    void set_c(shared_ptr<C> c) {c_ = c;}
};

class C {
private:
    shared_ptr<A> a_;
    shared_ptr<B> b_;
public:
    C() {cout << "C 생성자 호출" << endl;}
    ~C() {cout << "C 소멸자 호출" << endl;}
    void set_a(shared_ptr<A> a) {a_ = a;}
    void set_b(shared_ptr<B> b) {b_ = b;}
};

int main() {
    shared_ptr<A> a(new A);
    shared_ptr<B> b(new B);
    shared_ptr<C> c(new C);

    a->set_b(b);
    a->set_c(c);

    b->set_a(a);
    b->set_c(c);

    c->set_a(a);
    c->set_b(b);

    cout << "a.use_count(): " << a.use_count() << endl; // 3
    cout << "b.use_count(): " << b.use_count() << endl; // 3
    cout << "c.use_count(): " << c.use_count() << endl; // 3

    return 0;
}