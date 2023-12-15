#include<bits/stdc++.h>
using namespace std;
int flag = 0;

void cal(const vector<int>& v){
    for(auto i : v)
        cout << i << ' ';
    cout << endl;
}

template<typename T>
void go(T& v){
    if (flag)
        cal(v[0][0]); // 빌드 과정에서 문제가 발생한다.
    return;
}


int main(){
    vector<int> v1 = {1,2,3,4};
    vector<vector<vector<int>>> v2 = {
        {
            {1,2,3,4},
            {1,2,3,4}
        }
    };

    if(!flag)
        go(v2);
    else
        go(v1);
}