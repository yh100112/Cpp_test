#include<iostream>
#include<vector>

using namespace std;

class Item
{
  public:
    Item(const int _n) : m_nx(_n) {
      cout << "일반생성자 호출" << endl;
    }

    Item(const Item& rhs) : m_nx(rhs.m_nx){
      cout << "복사생성자 호출" << endl;
    }

    Item(const Item&& rhs) : m_nx(std::move(rhs.m_nx)){
      cout << "이동 생성자 호출" << endl;
    }

    ~Item(){
      cout << "소멸자 호출" << endl;
    }

  private:
    int m_nx;
};

int main(){
  vector<Item> v;

  // cout << "push_back호출" << endl;
  // v.push_back(Item(3));
  // push_back호출
  // 일반생성자 호출
  // 이동 생성자 호출
  // 소멸자 호출
  // 소멸자 호출
  


  cout << endl;
  cout << "emplace_back호출" << endl;
  v.emplace_back(3);
  // emplace_back호출
  // 일반생성자 호출
  // 소멸자 호출
}
