#include<iostream>
#include<thread>

class backgroundtask
{
    public:
        void operator ()() const{
            std::cout<<"Print A"<<std::endl;
            std::cout<<"Print B"<<std::endl;
        }
};

int main()
{
    backgroundtask f;
    /* std::thread mythread(f); correct way of passing thread */
    
    //std::thread mythread1((backgroundtask()));// correct way of passing thread
    std::thread mythread1{backgroundtask()};// correct way of passing thread
    //std::thread mythread1(f());// incorrect way of passing thread

    mythread1.join();
}
