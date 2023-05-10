#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

using namespace std;

template<typename T>
void printVectorElements(vector<T>& vec)
{
  for (auto i = 0; i < vec.size(); ++i) {
    cout << vec.at(i) << "; ";
  }
  cout << endl;
}

int main()
{
  vector<int> i_vec1 = {12, 32, 43, 53, 23, 65, 84};

  cout << "i_vec1            : ";
  printVectorElements(i_vec1);

  std::random_device rd;
  std::default_random_engine rng(rd());
  std::shuffle(i_vec1.begin(), i_vec1.end(), rng); // 첫번째, 두번째에 범위 이터레이터 넣어주고 세번째 인자에 난수 생성 엔진 넣어줌

  cout << "i_vec1 (shuffled) : ";
  printVectorElements(i_vec1);
  cout << endl;
}
