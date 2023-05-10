#include <cpp_redis/cpp_redis>
#include <iostream>

int main(void) {
  cpp_redis::client client;

  client.connect();

  client.set("hello", "42");
  client.get("hello", [](cpp_redis::reply& reply){
    std::cout << reply << std::endl;
  });

  client.sync_commit();
  // or client.commit(); => asynchronous call
}
