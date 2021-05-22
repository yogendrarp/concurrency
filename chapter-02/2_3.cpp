#include <iostream>
#include <thread>

class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread &t_) : t(t_)
    {
    }
    ~thread_guard()
    {
        if (t.joinable())
        {
            std::cout<<"Destroying Thread"<<std::endl;
            t.join();
        }
    }
    thread_guard(thread_guard const &) = delete;
    thread_guard &operator=(thread_guard const &) = delete;
};

struct func
{
    int& i;
    func(int& i_):i(i_){}

    void operator()()
    {
        for (unsigned j=0;j<10;j++)
        {
            std::cout<<i<<std::endl;
        }
    }
};

int main()
{
    int somelocalvalue=10;
    func myfunc(somelocalvalue);
    std::thread mythread(myfunc);
    thread_guard g(mythread);
    std::cout<<"Main thread"<<std::endl;
}