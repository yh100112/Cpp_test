#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> s {4,3,3,5,1,2,3};
    auto it = unique(s.begin(), s.end());
    cout << it - s.begin() << endl; // 6 -> 그대로 두는 위치를 반환
    cout << *it << endl; // 3
    cout << *s.end() << endl; // end()는 마지막 인자 다음 위치를 가리킴

    for(auto a : s)
        cout << a << " "; // 4 3 5 1 2 3 3
    cout << endl;
}