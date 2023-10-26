#include<iostream>
#include<mutex>
#include<thread>
#include<shared_mutex>
#include <memory>
using namespace std;

class Test{
private:
    shared_mutex sm;
    int count;

public:
    // count 읽기 작업
    int get(){
        std::shared_lock<std::shared_mutex> lock(sm);
        return count;
        // shared_lock을 사용하면 shared모드로 락을 획득하고 "객체 소멸자"에서 자동으로 락을 해제한다. ( sm.lock_shared()와 같은데 자동으로 락을 해제해줄 뿐 ) 
        // -> 공유락을 걸어주면 여러개 쓰레드가 동시에 들어와도 읽기 작업은 동시에 할 수 있다. 
        // -> get()은 "공유락"을 사용하므로 어떤 스레드든 동시에 공유락에 들어와 읽기 작업을 수행할 수 있다.
    }

    //count에 쓰기 작업
    void Add(int val){
        unique_lock<std::shared_mutex> lock(sm);
        count += val;
        return;
        // unique_lock을 사용하면 exclusive모드로 락을 획득하고 "객체 소멸자"에서 자동으로 락을 해제한다.
        // 쓰기 작업에서는 "일반락" 검 
        // -> 다른 스레드에서 읽기 작업 or 쓰기 작업에 들어가면 "공유락"이나 "일반락"이 걸리므로 락이 해제될 때까지 대기하게 된다.
        // -> get()이 먼저 호출되면 get()에서 공유락이 해제될 때까지 Add()는 동작하지 못하고 대기하게 된다.
    }
};

int main(){
    auto peo = std::make_shared<Test>();

    // shared모드로 데이터를 읽음
    thread read_thread([peo]{
        for(int i = 1; i <= 10; i++){
            cout << peo->get() << endl;
        }
    });

    //exclusive모드로 데이터를 씀
    thread write_thread([peo]{
        for(int i = 1; i <= 10; i++){
            peo->Add(i);
        }
    });

    read_thread.join();
    write_thread.join();
}

// compile
// -> g++ -o -std=c++17 t shared_mutex2.cpp -lpthread
