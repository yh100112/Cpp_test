#include<iostream>
#include<queue>
using namespace std;

struct cmp{
  bool operator()(pair<int,int>&a, pair<int,int>&b) {
    if(a.first == b.first) {
      return a.second > b.second; // 큰 걸 우선적으로
    }
    else {
      return a.first < b.first; // 작은걸 우선적으로
    }
  }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // 오름차순

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
22
25
12
13
*/