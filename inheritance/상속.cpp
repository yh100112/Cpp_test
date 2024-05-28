#include<iostream>
#include<string>

using namespace std;

class Person{
private:
    string name;
public:
    Person(string name){
        this->name = name;
    }
    string getName(){ return name; }
    void showName(){ cout << "이름 : " <<getName() << '\n'; }
};

class Student : private Person{ 
private:
    int studentID;
public:
    Student(int studentID, string name) : Person(name) {
        this->studentID = studentID;
    }

    void show(){
        cout << "-학생번호 : " << studentID << '\n';
        cout << "-학생이름 : " << getName() << '\n'; 
    }

    //오버라이딩
    void showName(){
        cout << "학생 이름 : " << getName() << '\n';
    }

};

int main(){
    Student student(1,"김덕용");
    student.show();
    student.showName();

    Person p("긴매매");
    p.showName(); // 이름 : 긴매매
    return 0;
}
