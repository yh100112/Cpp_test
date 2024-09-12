#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
  virtual void sound() = 0;
  void info(){
    std::cout << "동물은 숨을 쉽니다.\n";
  }
};

class Dog : public Animal{
private:
  std::string name;
public:
  Dog(std::string s) : name(s) {};
  void sound() { std::cout << "멍멍\n"; }
  void name_print() { std::cout << name << std::endl; }
  void only_dog() { std::cout << "이건 개 클래스\n"; }
};

class Cat : public Animal {
private:
  std::string name;
public:
  Cat(std::string s) : name(s) {};
  void sound() { std::cout << "냐옹\n"; }
  void name_print() { std::cout << name << std::endl; }
  void data() { std::cout << this << std::endl; }
  void only_cat() { std::cout << "이건 고양이 클래스\n"; }
};

int main() {
  std::vector<Animal*> v;
  v.emplace_back(new Cat("나비"));
  v.emplace_back(new Dog("멍멍이"));

  // 더 엄격히 검사해서 컴파일은 되지만 런타임시 에러가 발생한다.
  // Dog* cat = dynamic_cast<Dog*>(v[0]);
  // if (cat == nullptr) {
  //   std::cout << "캐스팅 실패\n";
  // }
  // Cat* dog = dynamic_cast<Cat*>(v[1]);
  // if (dog == nullptr) {
  //   std::cout << "캐스팅 실패\n";
  // }
  
  // 캐스팅 에러가 컴파일에서도 나지 않고 런타임시에도 나지 않는다.
  // 예상치 못한 결과가 나오므로 큰 문제다!!
  Dog* cat = (Dog*)v[0];
  Cat* dog = (Cat*)v[1];

  cat->name_print();  // 나비
  cat->sound();       // 냐옹
  cat->only_dog();    // 이건 개 클래스
  dog->name_print();  // 멍멍이
  dog->sound();       // 멍멍
  dog->only_cat();    // 이건 고양이 클래스
  return 0;
}
