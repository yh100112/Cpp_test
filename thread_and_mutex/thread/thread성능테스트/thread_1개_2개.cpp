#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<chrono>
using namespace std;

void cal(int start, int end, long long* result){
  volatile long long sum = 0;
  for(int i = start; i < end; ++i)
    sum += i;
  *result = sum;
}

long long single_thread_cal() {
  volatile long long sum = 0;
  for (int i = 1; i < 1000000000; i++)
    sum += i;
  return sum;
}

int main(){
  long long sums[2] = {0,};
  long long ret = 0;
  vector<thread> threads;

  auto startTime = chrono::high_resolution_clock::now();

  for(int i = 0; i < 2; i++)
    threads.push_back(std::thread(cal, i * 500000000, (i + 1) * 500000000, &sums[i]));

  for(int i = 0; i < 2; i++)
    threads[i].join();
  
  auto endTime = chrono::high_resolution_clock::now();

  chrono::duration<double> result = endTime - startTime;

  for(auto i : sums)
    ret += i;
  cout << ret + 1000000000 << endl;

  cout << "스레드 2개일 때 걸린 시간 : " << result.count() << endl;

  auto sTime = chrono::high_resolution_clock::now();
  cout << single_thread_cal() + 1000000000 << endl;
  auto eTime = chrono::high_resolution_clock::now();

  chrono::duration<double> r = eTime - sTime;
  cout << "싱글스레드일 때 걸린 시간 : " << r.count() << endl;
}
