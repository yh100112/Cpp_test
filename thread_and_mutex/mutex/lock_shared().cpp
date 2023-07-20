/* writer 스레드는 전역 변수 x,y에 1~9의 난수, x * y = z
 * reader 스레드는 x * y가 z와 같은지 여부를 확인한다.
 * 하나의 writer스레드와 7개의 reader스레드를 시작하고, 모든 스레드가 
 * 완료될 때까지의 시간을 측정해 보았다.
 */

#include<iostream>
#include<chrono>
#include<random>
#include<thread>
#include<mutex>
#include<shared_mutex>

using namespace std;

int x,y,z;
int bad_results;
shared_mutex mtx;

void writer(){
  mt19937 gen;
  uniform_int_distribution<int> dist(1,9);
  for(int i=0; i<100000; ++i){
    mtx.lock();
    x = dist(gen);
    y = dist(gen);
    z = x * y;
    mtx.unlock();
  }
  z = -1;
}

// 읽을 때 write를 못하게  lock하는 보통의 reader -> lock(), unlock()
void reader(){
  while(true){
    mtx.lock();
    
    if( z < 0 ) {
      mtx.unlock();
      break;
    }
    if( z != x * y) ++bad_results;
    
    mtx.unlock();
  }
}

// shared_reader ->  lock_shared(), unlock_shared()
void shared_reader(){
  while(true){
    mtx.lock_shared();
    
    if(z < 0){
      mtx.unlock_shared();
      break;
    }
    if (z != x * y) ++bad_results;

    mtx.unlock_shared();
  }
}

void run(bool shared){
  x = 0;
  y = 0;
  z = 0;
  bad_results = 0;

  const int Nread = 7; // read thread 7개
  thread threads[Nread + 1];

  auto start = chrono::high_resolution_clock::now();
  threads[0] = thread(writer);

  for(int i=1; i<=Nread; ++i){
    threads[i] = thread(shared ? shared_reader : reader);
  }
  for(thread& thr : threads) thr.join();

  auto stop = chrono::high_resolution_clock::now();

  cout << chrono::duration_cast<chrono::milliseconds>(stop-start).count() << "[ms] bad_results = " << bad_results << endl;
}

int main(){
  cout << "normal : "; 
  run(false);

  cout << "shared : ";
  run(true);
}



























