#include<iostream>
#include<mutex>
#include<thread>
#include<shared_mutex>
#include <memory>
using namespace std;

class ExampleObject{
private:
  shared_mutex sm;
  int count;

public:
  // count를 읽는 작업을 위해서 shared모드로 mutex 획득
  int get(){
    std::shared_lock<std::shared_mutex> lock(sm);
    // shared_lock을 사용하면 shared모드로 락을 획득하고 "객체 소멸자"에서 자동으로 락을 해제한다. ( sm.lock_shared()와 같은데 자동으로 락을 해제해줄 뿐 ) 
    // -> 공유락을 걸어주면 여러개 쓰레드가 동시에 들어와도 읽기 작업은 동시에 할 수 있다. 
    // 하지만 쓰기 작업일 경우는 일반락을 걸어서 공유락이 읽기 작업에서 걸리면 일반 락과 마찬가지로 락이 해제될 때까지 대기하게 된다.
    // 그래서 밑에 add함수는 일반락을 걸어줬으므로 get()에서 공유락이 해제될 때까지 동작하지 못하고 대기하게 된다.
    // 하지만 읽기 작업은 get()에서 공유락을 걸어줬으므로 어떤 스레드든 동시에 공유락에 들어와 읽기 작업을 수행할 수 있다.
    return count;
  }

  //count객체를 쓰는 작업을 위해서 exclusive모드로 mutex를 획득
  void Add(int val){
    unique_lock<std::shared_mutex> lock(sm);
    // unique_lock을 사용하면 exclusive모드로 락을 획득하고 "객체 소멸자"에서 자동으로 락을 해제한다.
    count += val;
  }
};

int main(){
  auto peo = std::make_shared<ExampleObject>();

  thread read_thread([peo]{
      // shared모드로 데이터를 읽음
      for(int i=0; i<10; i++){
        cout << peo->get() << endl;
      }
  });

  thread write_thread([peo]{
      //exclusive모드로 데이터를 씀
      for(int i=0; i<=10; i++){
        peo->Add(i);
      }
  });

  read_thread.join();
  write_thread.join();
}

// compile
// -> g++ -o -std=c++17 t shared_mutex2.cpp -lpthread
