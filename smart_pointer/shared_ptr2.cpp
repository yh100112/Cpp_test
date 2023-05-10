#include<iostream>
#include<memory>
using namespace std;

int main(){
  shared_ptr<int> s1 = make_shared<int>(10);
  cout << s1.use_count() << endl; // 1

  {
    shared_ptr<int> s2 = s1;
    cout << s1.use_count() << " " << s2.use_count() << endl; // 2 2
  }

  cout << s1.use_count() << endl; // 1
  cout << *s1 << endl;

  return 0;
}

