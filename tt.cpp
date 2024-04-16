#include<bits/stdc++.h>
using namespace std;
int n, a[1004], cnt[1004], ret = INT_MIN;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  // 재귀 구조라고 생각하고 초기 세팅을 어떻게 할지 생각하자. 어떻게 연속적으로 로직을 처리할까를 생각!!
  // -> 뒤를 바라보는 로직은 재귀랑 비슷하다. 처음 시작을 어떻게 할지를 잘 정하고 타고타고 들어가야 한다!!
  for (int i = 0; i < n; i++) {
    int maxValue = 0; // 최대증가부분수열(LIS)
    int cur = a[i];

    // 현재 위치 이전까지의 최대증가부분수열(LIS)을 찾음
    for (int j = 0; j < i; j++)
      if (a[j] < cur && maxValue < cnt[j])
        maxValue = cnt[j];

    cnt[i] = maxValue + 1; // 초기세팅 -> 첫 시작을 LIS를 1로 세팅해주는 것을 포함한다.
    ret = max(ret, cnt[i]);
  }
  cout << ret << "\n";
}