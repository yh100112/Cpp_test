#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

thread_local unsigned int i = 0;
mutex g_mutex;

void OnThread(int nid)
{
  ++i;
  unique_lock<mutex> lock(g_mutex);
  cout << nid << "-thread" << i << endl;
}

int main(){
  thread th1(OnThread, 0);
  thread th2(OnThread, 1);

  unique_lock<mutex> lock(g_mutex);
  cout << "main thread : " << i << endl;
  lock.unlock();

  th1.join();
  th2.join();

  return 0;
}
/*
 * 전역 변수로 선언된 i는 각각의 스레드에서 증가를 시킴에도 같은 값을 가지며, main스레드에서도 변하지 않은 값인 0이 출력된다.
 * thread_local을 사용했기 때문에 전역변수인 i는 각각의 스레드에서 독립적으로 사용하기 때문이다.
 */
