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

  // this_thread::get_id() 함수를 통해 현재 스레드의 아이디를 확인 가능
  thread::id this_id = std::this_thread::get_id();
  printf("쓰레드 %x에서 %d부터 %d까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);
  // cout 이 아닌 printf를 쓴 이유
  // - cout은 << 중간중간에 다른 쓰레드가 들어와 실행될 수 있음
  // - 하지만 printf는 ""안에 문장을 다 출력할 때까지 다른 쓰레드가 내용을 출력할 수 없다.
}

int main(){
    clock_t start, finish;

    vector<int> data(10000);
    for(int i = 0; i < 10000; i++){
        data[i] = i+1;
    }

    //각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    vector<int> partial_sums(4);

    vector<thread> workers;
    start = clock();
    for(int i = 0; i < 4; i++)
        workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i+1) * 2500, &partial_sums[i]));
    for(int i = 0; i < 4; i++)
        workers[i].join();
    finish = clock();
    cout << finish - start << endl;

    int total = 0;
    for(int i = 0; i < 4; i++)
        total += partial_sums[i];

    std::cout << "전체 합 : " << total << std::endl;
}
