#include<iostream>
#include<functional>
using namespace std;

class test_class_fn
{
    public:
        int add(int a, int b){
            return a + b;
        }

        auto get_func_mem_fn(){
            return mem_fn(&test_class_fn::add);
        }

        function<int(int, int)> get_func_bind(){
            return bind(&test_class_fn::add, this, std::placeholders::_1, std::placeholders::_2);
        }
};

int main(){
    test_class_fn test;

    auto func0 = test.get_func_mem_fn();
    function<int(int, int)> func1 = test.get_func_bind();

    cout << func0(test, 1, 2) << endl; // 3
    cout << func1(1,2) << endl; // 3
}

// 클래스 함수에 대한 포인터 호출을 편하게 해주는 함수들