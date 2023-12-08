#include<thread>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

void worker(vector<int64_t>::iterator start, vector<int64_t>::iterator end, int64_t* result){
  int64_t sum = 0;
  for(auto itr = start; itr < end; ++itr){
    sum += *itr;
  }
  *result = sum;

  thread::id this_id = std::this_thread::get_id();
  printf("쓰레드 %x에서 %lld부터 %lld까지 계산한 결과 : %lld \n", this_id, *start, *(end - 1), sum);
}

int main(){
  int64_t total = 0;
  vector<int64_t> data(100000000);
  vector<int64_t> partial_sums(2);
  vector<thread> threads;

  for(int i = 0; i < 100000000; i++) data[i] = i+1;

  auto startTime = chrono::high_resolution_clock::now();
  for(int i = 0; i < 2; i++) threads.push_back(thread(worker, data.begin() + i * 50000000, data.begin() + (i+1) * 50000000, &partial_sums[i]));
  for(int i = 0; i < 2; i++) threads[i].join();
  auto endTime = chrono::high_resolution_clock::now();

  chrono::duration<double> result = endTime - startTime;
  cout << "스레드 2개일 때 걸린 시간 : " << result.count() << endl;

  for(int i = 0; i < 2; i++)
    total += partial_sums[i];

  std::cout << "전체 합 : " << total << std::endl;
}
