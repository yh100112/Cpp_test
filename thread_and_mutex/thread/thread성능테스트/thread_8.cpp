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
    int sums[8] = {0,};

    start = clock();
    
    vector<thread> threads;
    for(int i = 0; i < 8; i++)
        threads.push_back(std::thread(cal, i * 1250, (i + 1) * 1250, &sums[i]));

    for(int i = 0; i < 8; i++)
        threads[i].join();
    
    finish = clock();

    cout << accumulate(sums, sums + 8, 0) + 10000 << endl;
    cout << "스레드 8개일 때 걸린 시간 : " << finish - start << endl;
}