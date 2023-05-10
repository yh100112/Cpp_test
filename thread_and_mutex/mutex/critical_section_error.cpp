#include<iostream>
#include<thread>
#include<vector>

void worker(int& counter){
  for(int i = 0; i < 10000; i++){
    counter += 1;
  }
}
//쓰레드들이 공통된 변수인 counter에 1을 더하는데 
//스레드 1에서 1을 더하는 도중 스레드2에서 1을 더하면 실제로는 2가 더해진 것인데
//스레드 1이 더하는 도중 스레드2가 counter에 접근해 1을 더한 것이므로 스레드2는 counter가 0
//인 상태에서 1을 더한 것이 된다. 그래서 값이 40000이 안나오는 경우도 있는 것이다.
// -> thread를 사용할 때는 전역변수는 왠만해서는 사용하지 않는게 좋다.
int main(){
  int counter = 0;

  std::vector<std::thread> workers;
  for(int i = 0; i < 4; i++){
    workers.push_back(std::thread(worker, std::ref(counter)));
  }

  for(int i = 0; i < 4; i++){
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}
