#include <iostream>
#include <string>
using namespace std;

class BaseClass {
public:
    int sum;
    virtual void display() const {
        std::cout << "BaseClass::display()" << std::endl;
    }

    virtual BaseClass* clone() const;
};

BaseClass* BaseClass::clone() const {
    return new BaseClass(*this);
} 

class DerivedClass : public BaseClass {
public:
    void display() const {
        std::cout << "DerivedClass::display()" << std::endl;
    }

    DerivedClass* clone() const {
        return new DerivedClass(*this);
    }
};

int main() {
    // 객체 포인터를 생성하고 초기화
    BaseClass* originalPointer = new DerivedClass();
    originalPointer->sum = 500;

    // 가상 복사 생성자(clone)를 통해 새로운 객체 생성
    BaseClass* copiedPointer = originalPointer->clone();

    // 호출 결과는 "DerivedClass::display()"가 됩니다.
    copiedPointer->display();

    cout << originalPointer->sum << endl;
    copiedPointer->sum = 10;
    cout << originalPointer->sum << endl;

    // 메모리 누수 방지를 위해 포인터들을 삭제
    delete originalPointer;
    delete copiedPointer;

    return 0;
}
