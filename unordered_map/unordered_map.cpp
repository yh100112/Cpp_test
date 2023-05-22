#include<iostream>
#include<string>
#include<unordered_map> 
using namespace std;

int main(){
  unordered_map<string,int> um;

  if(um.empty()){
    printf("unordered_map은 비어있다.\n");
  }

  um.insert(unordered_map<string,int>::value_type({"key",1}));
  um.insert({"melon",3});
  um.insert({"apple",5});

  printf("unordered_map의 크기 : %lu\n",um.size());

  for(auto elem : um){
    cout << "key : " << elem.first << " value : " << elem.second << endl;
  }

  unordered_map<int, int> um2;
  um2[3]++;            //map과 마찬가지로 그냥 um2[] 이렇게만 하면 알아서 키와 쌍을 이루는 value를 넣어줌 (int이므로 0을 넣어줌)
  printf("%d\n",um2[3]); // 1
}
/*
 * unordered_map은 key를 정렬해주지 않는다. ( hash table로 구현되어 있기 때문 )
 */
