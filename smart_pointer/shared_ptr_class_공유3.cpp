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
        // cout << "Address 생성자 호출: " << m_street << ", " << m_city << endl; 
    }

    ~Address() { 
        // cout << "Address 소멸자 호출: " << m_street << ", " << m_city << endl; 
    }
    string getStreet() const { return m_street; }
    string getCity() const { return m_city; }
};

class Person {
private:
    string m_name;
    shared_ptr<Address> m_address;
public:
    Person(const string& name, const string& street, const string& city) 
    : m_name(name), 
      m_address(make_shared<Address>(street, city)) 
    { 
        // cout << "Person 생성자 호출: " << m_name << endl; 
    }

    ~Person() {
        // cout << "Person 소멸자 호출: " << m_name << endl;
    }
    string getName() const { return m_name; }

    // 이 경우 반환할 때 shared_ptr<Address>를 복사하여 새로운 임시 shared_ptr<Address> 객체가 생성되어 이로 인해 use_count()가 2가 된다!!
    // shared_ptr<Address> getAddress() const { 
    //     return m_address; 
    // }

    // 이렇게 참조로 반환해야 use_count()가 증가하지 않는다.
    shared_ptr<Address>& getAddress() { 
        return m_address; 
    }
};

int main() {
    // 두 개의 Person 객체를 생성합니다.
    shared_ptr<Person> person1(new Person("Alice", "대은로", "서울"));
    shared_ptr<Person> person2(new Person("Bob", "은행로", "서울"));
    
    cout << person1->getAddress().use_count() << endl;
    cout << person2->getAddress().use_count() << endl;

    cout << person2.use_count() << endl;
    cout << person1.use_count() << endl;
}