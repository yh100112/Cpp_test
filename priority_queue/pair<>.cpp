#include<iostream>
#include<queue>
using namespace std;

priority_queue<pair<int,int>> pq;

int main(){
  pq.push({1,2});
  pq.push({1,3});
  pq.push({2,2});
  pq.push({2,5});
  pq.push({3,1});

  while(!pq.empty()) {
    cout << pq.top().first << pq.top().second << endl;
    pq.pop();
  }
}
/*
31
25
22
13
12
*/