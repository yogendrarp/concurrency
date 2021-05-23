#include <thread>
#include <mutex>

class some_big_object;
void swap(some_big_object &lhs, some_big_object &rhs);
class X
{
private:
    some_big_object det;
    std::mutex m;

public:
    X(some_big_object const &sd) : det(sd) {}
    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs)
            return;
        std::lock(lhs.m,rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_a(rhs.m, std::adopt_lock);
        swap(lhs.det,rhs.det);
    }
}
