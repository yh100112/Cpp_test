#include<rapidjson/document.h>
#include<iostream>

using namespace rapidjson;
using namespace std;

int main(){

  // const char* json2 = "{ \"data\":[{\"packet\":\"data1\",\"msg\":\"msg1\"}"",{\"packet\":\"data2\",\"msg\":\"msg2\"}] }";
  // Document d;
  // d.Parse(json2);
  // Value& aa = d["data"];
  //
  // if (aa.GetType() == kArrayType) {
  //   cout << "json2 data is array!" << endl;
  // }

  const char* json = "{\"hello\": \"world\",\"t\": true, \"f\": false, \"n\": null, \"i\": 123, \"pi\": 3.1416, \"a\": [1, 2, 3, 4]}";
  /*
   * {
   *   "hello": "world",
   *   "t": true,
   *   "f": false,
   *   "n": null,
   *   "i": 123,
   *   "pi": 3.1416,
   *   "a": [1, 2, 3, 4]
   * }
  */

  Document document;
  document.Parse(json); // document에 json data parsing

  // -------------------------------------------------------------
  // "hello"에 접근
  if(document.IsObject()){
    cout << "object!" << endl;
  }

  // json이 {} 형태이므로 GetType()을 하면 Object이다.
  if (document.GetType() == kObjectType) { 
    cout << "ooooobbbbject!!" << endl;
  }

  if(document.HasMember("hello")){
    cout << "hello exist" << endl;
  }

  if(document["hello"].IsString()){
    cout << "hello is string type" << endl;
  }
  printf("hello = %s\n", document["hello"].GetString());

  // -------------------------------------------------------------
  // "t"에 접근

  if(document["t"].IsBool()){
    cout << "t is bool type" << endl;
  }
  printf("t = %s\n", document["t"].GetBool() ? "true" : "false");
  printf("n = %s\n", document["n"].IsNull() ? "null" : "?");

  // -------------------------------------------------------------
  // "i"에 접근

  if(document["i"].IsNumber()){
    cout << "i is number" << endl;
  }

  //이 경우엔 특이하게, IsUnit() / IsInt64() / IsUnit64() 셋 다 true를 반환한다.
  if(document["i"].IsInt()){
    cout << "i is int type" << endl;
  }
  printf("i = %d\n", document["i"].GetInt());

  // -------------------------------------------------------------
  // "pi"에 접근
  
  if(document["pi"].IsNumber()){
    cout << "pi is number" << endl;
  }
  if(document["pi"].IsDouble()){
    cout << "pi is double type" << endl;
  }
  printf("pi = %.4f\n", document["pi"].GetDouble());

  // -------------------------------------------------------------
  // 배열을 value로 가지고 있는 "a"에 접근
  
  const Value& a = document["a"];
  if(a.IsArray()){
    cout << "a의 value는 array형태입니다." << endl;
  }

  // SizeType은 unsigned의 typedef이다.
  // 배열 인덱스값 호출방법 1
  for(SizeType i = 0; i < a.Size(); i++) // Uses SizeType instead of size_t
    printf("a[%d] = %d\n", i, a[i].GetInt());

  // 배열 인덱스값 호출방법 2
  for(Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
    printf("%d ", itr->GetInt());
  cout << endl;

  // 배열 인덱스값 호출방법 3
  for(auto& v : a.GetArray())
    printf("%d ", v.GetInt());
  cout << endl;
  

  Value::ConstMemberIterator itr = document.FindMember("hello");
  if(itr != document.MemberEnd())
    printf("%s\n", itr->value.GetString()); // world

  // -------------------------------------------------------------
  // json value값 비교하는 방법

  // 1.
  if (document["hello"] == document["n"]){
    cout << "same!" << endl;
  }else{
    cout << "different!" << endl;
  } 

  // 2.  
  if (document["hello"] == "world"){
    cout << "same!" << endl;
  }else{
    cout << "different!" << endl;
  } 

  // // 3. int value비교
  // if (document["i"] != 123)
  //
  //
  // // 4. double value비교
  // if (document["pi"] != 3.14)
  

}
