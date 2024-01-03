#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass 생성자 호출" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass 소멸자 호출" << std::endl;
    }
};

int main() {
    // MyClass 객체를 생성하여 shared_ptr로 래핑합니다.
    std::shared_ptr<MyClass> ptr1(new MyClass);

    // ptr1과 동일한 MyClass 객체를 참조하는 또 다른 shared_ptr을 만듭니다.
    std::shared_ptr<MyClass> ptr2(ptr1);

    // ptr1과 ptr2 모두가 객체를 참조하고 있습니다.
    std::cout << "ptr1.use_count(): " << ptr1.use_count() << std::endl;
    std::cout << "ptr2.use_count(): " << ptr2.use_count() << std::endl;

    // ptr1을 해제합니다.
    ptr1.reset();

    // ptr1이 해제되었으므로 ptr2만 객체를 참조하고 있습니다.
    std::cout << "ptr1이 해제되었으므로 ptr2만 객체를 참조합니다." << std::endl;
    std::cout << "ptr2.use_count(): " << ptr2.use_count() << std::endl;

    return 0;
}