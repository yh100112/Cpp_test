#include<iostream>
#include<thread>
using namespace std;

int main(){
  uint32_t core_count = std::thread::hardware_concurrency();
  cout << core_count << endl; // 8
  return 0;
}

