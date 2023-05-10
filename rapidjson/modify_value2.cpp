#include<rapidjson/document.h>
#include<iostream>

using namespace rapidjson;
using namespace std;

int main() {
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

  Document document;
  document.Parse(json);

  Value bb(kArrayType);
  Document::AllocatorType& allocator = document.GetAllocator();

  for (int i = 5; i <= 10; ++i) {
    bb.PushBack(i, allocator);
  }

  bb.PushBack("Lua", allocator).PushBack("Mio", allocator);

  // bb = [5,6,7,8,9,10,Lua,Mio]

}
