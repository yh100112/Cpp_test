#include<iostream>
using namespace std;

class Base{
public:
	void testFunc(){
    	cout << "Base Func" << '\n';
    }

    virtual void func2() {
        cout << "parent" << endl;
    }
};

class Derived : public Base{
public:
	void testFunc(){
    	cout << "Derived Func" << '\n';
    }
    
    virtual void func2() {
        cout << "child" << endl;
    }
};
int main(){
    Base* dynamicB = new Derived();
    dynamicB->testFunc(); // 출력 : Base Func dynamicB가 선언된 자료형인 Base에 접근한다.
    dynamicB->func2();    // 출력 : child -> virtual로 선언했기 때문에 어떤 클래스(인스턴스)를 할당하냐에 따라 접근하는 부분을 다르게 할 수 있다. // 동적바인딩
    delete dynamicB;
}