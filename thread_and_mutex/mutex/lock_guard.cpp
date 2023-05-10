#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
using namespace std;

void worker(int& result, std::mutex& m){
  for(int i=0; i<10000; i++){
    std::lock_guard<std::mutex> lock(m);// lock생성 시에 m.lock()을 실행한다고 보면 됨
    result += 1;
    
    //scope를 빠져나가면 lock이 소멸되면서 m을 자동으로 unlock해준다. -> lock_guard는 자동으로 락 사용이 끝나면 unlock해줌
  }
}

int main(){
  int counter = 0;
  std::mutex m; // mutex객체 생성

  vector<thread> workers;
  for(int i=0; i<4; i++){
    workers.push_back(std::thread(worker, std::ref(counter), std::ref(m))); // thread에서 실행하는 함수에 매개변수가 참조일 때는  ref()로 전달 -> 그냥 전달하면 에러남
  }

  for(int i=0; i<4; i++){
    workers[i].join(); // workers 쓰레드가 작업을 다 끝낼 때까지 main은 대기
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}
