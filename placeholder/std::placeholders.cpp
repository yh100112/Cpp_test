#include <functional>
#include <string>
#include <iostream>
 
void goodbye(const std::string& s)
{
  std::cout << "Goodbye " << s << '\n';
}
 
class Object {
public:
  void hello(const std::string& s)
  {
    std::cout << "Hello " << s << '\n';
  }

  void profile(const std::string& name, int age)
  {
    std::cout << "name : " << name << std::endl;
    std::cout << "age : " << age << std::endl;
  }
};


int main()
{
  Object instance;
  std::string str("World");

  std::function<void(const std::string&)> f = std::bind(&Object::hello, &instance, std::placeholders::_1);
  f(str);  // equivalent to instance.hello(str)

  f = std::bind(&goodbye, std::placeholders::_1);
  f(str);  // equivalent to goodbye(str)

  std::function<void(const std::string& name, int age)> test = std::bind(&Object::profile, &instance, std::placeholders::_1, std::placeholders::_2);
  test("kimdeokyong", 26);
}
