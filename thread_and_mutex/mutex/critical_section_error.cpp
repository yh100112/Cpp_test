#include<iostream>
#include<thread>
#include<vector>
using namespace std;


void worker(int& counter){
  for(int i = 0; i < 10000; i++)
    counter += 1;
}
int main(){
  int counter = 0;

  vector<thread> workers;
  for(int i = 0; i < 4; i++)
    workers.push_back(thread(worker, ref(counter)));

  for(int i = 0; i < 4; i++)
    workers[i].join();

  cout << "Counter 최종 값 : " << counter << endl;
}
/*
쓰레드들이 공통된 변수인 counter에 1을 더하는데 스레드 1에서 1을 더하는 도중 스레드2에서 1을 더하면 실제로는 2가 더해진 것인데
스레드 1이 더하는 도중 스레드2가 counter에 접근해 1을 더한 것이므로 스레드2는 counter가 0인 상태에서 1을 더한 것이 된다. 
그래서 값이 예상치 못한 값이 나오는 경우가 생긴다.
*/