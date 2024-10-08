#include<vector>
#include<iostream>
using namespace std;

int main()
{
  vector<int> a(5); // 뒤에 디폴트값 0이 숨어있음 즉, 벡터를 0값으로 사이즈 5만큼 만든다는 뜻
  a.emplace_back(1);
  a.emplace_back(2);
  a.emplace_back(3);
  a.emplace_back(4);
  a.emplace_back(5);

  for(auto& v : a)
    cout << v << endl; // 0 0 0 0 0 1 2 3 4 5  -> 그래서 emplace_back으로 넣으면 0 0 0 0 0 뒤에 들어감
  cout << a.size() << endl; // 10

  vector<int> t(3, 5); // 5 5 5

  vector<int> b(2);
  b[0] = 3;
  b[1] = 4;

  cout << b[2] << endl; // 0

  // vector<vector<int>> c(3); 
  vector<vector<int>> c; 
  c.resize(3); // 위 c(3)과 같은 의미
  for(auto v: c){
    for(auto vv: v){
      cout << vv << " ";
    }
    cout << "---" << endl;
  }
}

