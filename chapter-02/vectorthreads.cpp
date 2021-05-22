#include <iostream>
#include <thread>
#include <vector>

void do_work(unsigned id);

void somefunc()
{
    std::thread::id id = std::this_thread::get_id();
}

void f()
{
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; i++)
    {
        threads.__emplace_back(do_work, i);
    }

    for (auto &entry : threads)
    {
        entry.join();
    }
}