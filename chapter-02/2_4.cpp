#include <iostream>
#include <string>
#include <thread>

void open_document_and_display_gui(std::string filename);
bool done_editing();

struct user_command
{
    /* data */
};

user_command get_user_input();

void edit_document(std::string const &filename)
{
    open_document_and_display_gui(filename);

    while (!done_editing())
    {
        user_command cmd = get_user_input();
    }
    if (cmd.type == open_new_document)
    {
        std::string const new_name = get_filename_from_user();
        std::thread t(edit_document, new_name);
        t.detach();
    }
    else
    {
        process_user_input(cmd);
    }
}