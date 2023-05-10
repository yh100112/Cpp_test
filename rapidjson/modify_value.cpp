#include<rapidjson/document.h>
#include<iostream>

using namespace rapidjson;
using namespace std;

int main(){
  const char* json = "{\"parent\" : {\"child\" : [1,2,3,4]}}";
  /*
   * {
   *   "parent" : {
   *     "child" : [1,2,3,4]
   *   }
   */

  Document document;
  document.Parse(json);


  document["parent"]["child"].Clear(); // 기존 값 초기화
  rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

  for (int16_t i = 10; i < 20; ++i) {
    document["parent"]["child"].PushBack(i, allocator); 
  }

  for(auto& v : document["parent"]["child"].GetArray()) {
    cout << v.GetInt() << " ";
  }
  cout << endl;
}

