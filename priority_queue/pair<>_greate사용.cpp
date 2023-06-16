#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 오름차순

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
12
13
22
25
31
*/