#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<numeric>
using namespace std;
void cal(int start, int end, int* result){
    int sum = 0;
    for(int i = start; i < end; ++i)
        sum += i;

    *result = sum;
}

int main(){
    clock_t start, finish;
    int sums[4] = {0,};

    start = clock();
    
    vector<thread> threads;
    for(int i = 0; i < 4; i++)
        threads.push_back(std::thread(cal, i * 2500, (i + 1) * 2500, &sums[i]));

    for(int i = 0; i < 4; i++)
        threads[i].join();
    
    finish = clock();

    cout << accumulate(sums, sums + 4, 0) + 10000 << endl;
    cout << "스레드 4개일 때 걸린 시간 : " << finish - start << endl;
}