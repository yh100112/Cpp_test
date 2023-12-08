#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<chrono>
using namespace std;

void cal(int start, int end, long long* result){
  long long sum = 0;
  for(int i = start; i < end; ++i)
    sum += i;
  *result = sum;
}

int main(){
  long long sums[4] = {0,};
  long long ret = 0;
  vector<thread> threads;

  auto startTime = chrono::high_resolution_clock::now();

  for(int i = 0; i < 4; i++)
    threads.push_back(std::thread(cal, i * 250000000, (i + 1) * 250000000, &sums[i]));
  for(int i = 0; i < 4; i++)
    threads[i].join();
  
  auto endTime = chrono::high_resolution_clock::now();

  chrono::duration<double> result = endTime - startTime;

  for(auto i : sums)
    ret += i;
  cout << ret + 1000000000 << endl;

  cout << "스레드 4개일 때 걸린 시간 : " << result.count() << endl;
}
