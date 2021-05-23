#include <list>
#include <mutex>
#include <algorithm>

std::list<int> variable_list;
std::mutex mutex_lock;

void add_to_list(int item)
{
    std::lock_guard<std::mutex> guard(mutex_lock);
    variable_list.push_back(item);
}

bool list_contains(int value_to_check)
{
    std::lock_guard<std::mutex> guard(mutex_lock);
    return std::find(variable_list.begin(), variable_list.end(), value_to_check) != variable_list.end();
}