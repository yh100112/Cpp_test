#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    string a[3] = {"111", "222", "33"};
    sort(a, a + 3, compare);
    for(string b : a) cout << b << " ";
}
/*
"33" "111" "222"
- string은 서로 비교할 때 왼쪽에서부터 아스키코드순으로 비교한다.
*/