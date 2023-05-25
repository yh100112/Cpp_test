#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> s {4,3,3,5,1,2,3};
    // unique(s.begin(), s.end()); //4 3 5 1 2 3 3
    s.erase(unique(s.begin(), s.end()), s.end()); // 4 3 5 1 2 3 -> 이상해짐

    vector<int> s2 {4,3,3,5,1,2,3};
    sort(s2.begin(), s2.end()); // 1 2 3 3 3 4 5
    s2.erase(unique(s2.begin(), s2.end()), s2.end()); // 1 2 3 4 5
}