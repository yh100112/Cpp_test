#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v {1,1,2,2,3,3,4,4,5,5};
    auto it = unique(v.begin(), v.end()); // 1 2 3 4 5 3 4 4 5 5
    cout << it - v.begin() << "\n"; // 5 -> unique()는 그대로 두는 요소의 처음 위치(iterator)를 반환

    vector<int> test {1,1,2,2,3,3,5,6,7,8,9};
    unique(test.begin(), test.end()); // 1 2 3 5 6 7 8 9 7 8 9
    
    vector<int> s {4,3,3,5,1,2,3};
    unique(s.begin(), s.end()); //4 3 5 1 2 3 3
}
/*
unique()
- 범위안에 있는 요소들 중 앞에서부터 서로를 비교해가며 중복되는 요소를 제거한 후 나머지 요소들은 삭제하지 않고 그대로 두는 함수    

vector test의 경우 unique()는
1 1 서로를 비교 -> 1
2 2 서로를 비교 -> 2
3 3 서로를 비교 -> 3
그리고 쭉 5, 6, 7, 8, 9 를 배열에 채워넣는다.
채워넣지 않은 영역의 요소인 7, 8, 9는 건드리지 않는다.
*/