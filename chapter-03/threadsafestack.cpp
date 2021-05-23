#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception
{
    const char *what() const throw();
};

template <typename T>

class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack() {}
    //Copy performed in constructor
    threadsafe_stack(const threadsafe_stack &other)
    {
        std::lock_guard<std::mutex> lock(other m);
        data = other.data;
    }
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;
    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        std::shared_ptr<T> const res(std::make_shared<T>(data.pop()));
        data.pop();
        return res;
    }
    void pop(T &value)
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
