#include <random>
#include <iostream>
 
int main()
{
  std::random_device rd;
  std::default_random_engine rg(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0); // 0 이상 1미만실수를 균등하게 뽑음
  for (int n = 0; n < 10; ++n) {
    std::cout << dis(rg) << ' ';
  }
  std::cout << std::endl;

  std::uniform_real_distribution<> dist(0.0, 100.0);
  for (int n = 0; n < 10; ++n) {
    std::cout << dist(rg) << ' ';
  }
  std::cout << '\n';
}
