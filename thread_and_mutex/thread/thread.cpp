#include<thread>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result){
  int sum = 0;
  for(auto itr = start; itr < end; ++itr){
    sum += *itr;
  }
  *result = sum;

  thread::id this_id = std::this_thread::get_id();
  printf("쓰레드 %x에서 %d부터 %d까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);
}

int main(){
    clock_t start, finish; 

    vector<int> data(10000);
    for(int i = 0; i < 10000; i++){
        data[i] = i+1;
    }

    //각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    vector<int> partial_sums(2);

    vector<thread> workers;
    start = clock();
    for(int i = 0; i < 2; i++)
        workers.push_back(thread(worker, data.begin() + i * 5000, data.begin() + (i+1) * 5000, &partial_sums[i]));
    for(int i = 0; i < 2; i++)
        workers[i].join();
    finish = clock();
    cout << finish - start << endl;

    int total = 0;
    for(int i = 0; i < 2; i++)
        total += partial_sums[i];

    std::cout << "전체 합 : " << total << std::endl;
}
