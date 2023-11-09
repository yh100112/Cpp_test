#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Monster
{
  private:
    string name_;
    float hp_;
    float damage_;

  public:
    Monster(const string& name, float hp, float damage); // 생성자 선언

    ~Monster(){ cout << "메모리 해제" << endl; }

    void PrintMonsterInfo();
};

Monster::Monster(const string& name, float hp, float damage)
{
  name_ = name;
  hp_ = hp;
  damage_ = damage;

  cout << "생성자 호출" << endl;
}

void Monster::PrintMonsterInfo()
{
  cout << "몬스터 이름 : " << name_ << endl;
  cout << "체력 : " << hp_ << endl;
  cout << "공격력 : " << damage_ << endl;
}

int main()
{
  shared_ptr<Monster> dragon = make_shared<Monster>("드래곤", 5000.f, 500.f);

  cout << "현재 소유자 수 : " << dragon.use_count() << endl; // 1

  auto dragon2 = dragon;
  cout << "현재 소유자 수 : " << dragon.use_count() << endl; // 2

  dragon2->PrintMonsterInfo();

  dragon2.reset(); // dragon2 해제

  cout << "현재 소유자 수 : " << dragon.use_count() << endl; // 1
}
