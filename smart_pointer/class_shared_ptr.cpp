#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Address {
private:
    string m_street;
    string m_city;
public:
    Address(const string& street, const string& city) 
    : m_street(street), 
      m_city(city) 
    { 
      cout << "Address 생성자 호출: " << m_street << ", " << m_city << endl; 
    }
    
    ~Address() 
    { 
      cout << "Address 소멸자 호출: " << m_street << ", " << m_city << endl; 
    }
    
    string getStreet() const { return m_street; }
    string getCity()   const { return m_city;   }
};

class Person {
private:
    string m_name;
    shared_ptr<Address> m_address; // shared_ptr을 통해 Address 객체를 공유
public:
    Person(const string& name, const string& street, const string& city) 
    : m_name(name), 
      m_address(make_shared<Address>(street, city)) 
    { 
      cout << "Person 생성자 호출: " << m_name << endl;
    }
    
    ~Person()
    {
      cout << "Person 소멸자 호출: " << m_name << endl;
    }
    
    string getName() const { return m_name; }
    shared_ptr<Address> getAddress() const { return m_address; }
};

int main() {
    // 두 개의 Person 객체를 생성합니다.
    shared_ptr<Person> person1(new Person("Alice", "123 Main St", "Anytown"));
    shared_ptr<Person> person2(new Person("Bob", "456 Elm St", "Anytown"));
    
    // person1과 person2가 참조하는 Address 객체를 출력합니다.
    cout << "person1이 참조하는 Address 객체: " << person1->getAddress()->getStreet() << ", " << person1->getAddress()->getCity() << endl;
    cout << "person2가 참조하는 Address 객체: " << person2->getAddress()->getStreet() << ", " << person2->getAddress()->getCity() << endl;
    
    // person1과 person2의 Address 객체가 같은지 확인합니다.
    if (person1->getAddress() == person2->getAddress()) {
        cout << "person1과 person2가 같은 Address 객체를 참조합니다." << endl;
    } else {
        cout << "person1과 person2가 다른 Address 객체를 참조합니다." << endl;
    }

    cout << person1.use_count() << endl; // 1
    cout << person2.use_count() << endl; // 1

    // person1을 삭제합니다.
    person1.reset();

    if (person2->getAddress())
        cout << "person2가 참조하는 Address 객체: " << person2->getAddress()->getStreet() << ", " << person2->getAddress()->getCity() << endl;
}
