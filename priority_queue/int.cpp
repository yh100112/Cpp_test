#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
priority_queue<int> pq2; // 내림차순 -> 기본값은 내림차순이라 단순히 이렇게만 쓰면 해당 타입에 대한 내림차순으로 설정됨
priority_queue<int, vector<int>, less<int>> pq3; // 내림차순

int main() {
    for(int i = 5; i >= 1; i--) {
        pq.push(i);
        pq2.push(i);
        pq3.push(i);
    }

    while(pq.size()) {
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << "\n";
        pq.pop();
        pq2.pop();
        pq3.pop();
    }
    /*
    1 : 5 : 5
    2 : 4 : 4
    3 : 3 : 3
    4 : 2 : 2
    5 : 1 : 1
    */
}