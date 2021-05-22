#include <iostream>
#include <thread>
#include <string>

void f(int i, std::string const &s);
void oops(int some_param)
{
    char buffer[1024];
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 3, buffer);
    t.detach();
}

void update_data_for_widget(widget_id w, widget_data &data);
void oops_again(widget_id w)
{
    widget_data data;
    std::thread t(update_data_for_widget, w, std::ref(data));
    display_status();
    t.join();
    process_widget_data(data);
}