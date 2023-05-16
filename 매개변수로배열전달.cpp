#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> result;
    int duplicate[101] = {0,};
    for(int i = 0; i < arr.size(); ++i) {
         duplicate[arr[i]]++;
    }

    for(int i = 1; i < 101; ++i) {
        if (duplicate[i] > 1) {
            result.push_back(duplicate[i]);            
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    }
    return result;
};

int main(){
    vector<int> arr = {3,2,4,4,2,5,2,5,5};
    vector<int> ans = solution(arr);
    for(auto& v: ans)
        cout << v << " ";
    cout << endl;
}