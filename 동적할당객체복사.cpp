#include <iostream>
#include <string>

class BaseClass {
public:
    virtual void display() const {
        std::cout << "BaseClass::display()" << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void display() const override {
        std::cout << "DerivedClass::display()" << std::endl;
    }
};

int main() {
    // 객체 포인터를 생성하고 초기화
    BaseClass* originalPointer = new DerivedClass();

    // 객체 포인터를 복사하여 새로운 객체 포인터 생성
    BaseClass* copiedPointer = new BaseClass(*originalPointer);

    // 호출 결과는 "BaseClass::display()"가 됩니다.
    copiedPointer->display();

    // 메모리 누수 방지를 위해 포인터들을 삭제
    delete originalPointer;
    delete copiedPointer;

    return 0;
}

/*
이 코드에서 DerivedClass가 BaseClass를 상속받아 display() 함수를 재정의하고 있습니다. 그런데 BaseClass의 포인터로 DerivedClass 객체를 가리키고, 이를 복사 생성자로 복사하면 복사된 객체의 display() 함수는 BaseClass::display()가 호출됩니다. 따라서 복사 생성자는 단순히 기본 클래스의 내용만을 복사하고, 파생 클래스에서 추가된 내용은 복사하지 않습니다.
*/