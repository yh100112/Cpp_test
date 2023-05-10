#include<iostream>
#define aa(req) \
  for (int i = 0; i < 5; ++i) { \
    cout << i << endl; \
  }

using namespace std;

int main() {
  aa("ee");
  aa(2);
}
