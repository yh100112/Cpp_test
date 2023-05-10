#include <iostream>
#include <functional>
using namespace std;

int sum(int a, int b, int c)
{
  return a+b+c;
}

int main()
{
  std::function<int (int)>func1 = std::bind(sum, std::placeholders::_1, 2, 3);
  // std::function<int (int, int, int)>func1 = std::bind(sum, std::placeholders::_1, placeholders::_2, placeholders::_3);
  cout << func1(2) << endl;
  
  // auto func1 = std::bind(sum, std::placeholders::_1, 2, 3); //auto로 하면 오류 안남
  // cout<< func1(2) << endl; 
}
