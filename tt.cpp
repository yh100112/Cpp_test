#include<bits/stdc++.h>
using namespace std;
int t, n;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    
    sort(a, a + n);
    int mx = INT_MIN;
    for (int i = 0; i < n - 2; i++)
      mx = max(mx, abs(a[i] - a[i + 2]));
    cout << mx << "\n";
  }
}