#include<iostream>
#include<memory>
using namespace std;

class stat
{
    public:
        stat();
        void init();
        int64_t bet_;
        int32_t base_spin_cnt_;
};

stat::stat() :
    bet_(0),
    base_spin_cnt_(0)
{
    cout << "constructor call" << endl;
}

void stat::init()
{
    cout<< "초기화" << endl;
}


int main(){
    shared_ptr<stat> stat_;
    stat_->bet_ = 1000;
}