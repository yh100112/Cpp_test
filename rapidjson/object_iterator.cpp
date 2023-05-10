#include<rapidjson/document.h>
#include<iostream>
#include<stdio.h>

using namespace rapidjson;
using namespace std;

int main () {
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
   *}
  */

  static const char* kTypeNames[] = { "Null", "False", "True", "Object", "Array", "String", "Number" };

  Document document;
  document.Parse(json);
   
  for (Value::ConstMemberIterator itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr) {
    cout << itr->name.GetString() << " " << itr->value.GetType() << endl;
  }
}
