#include<iostream>
#include<thread>

std::thread f()
{
    void somefunction();
    return std::thread(somefunction); 
}

std::thread g()
{
    void some_other_function(int);
    std::thread t(some_other_function,42);
    return t;
}
