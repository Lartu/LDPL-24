#include "../state.cpp"
#include <iostream>

string fix_number(NUMBER in)
{
    string s = to_string(in);
    size_t dot = s.find_first_of('.');
    if (dot != string::npos)
    {
        // Find the last non-zero character after the dot
        size_t last = s.find_last_not_of('0');
        // If the last non-zero character is the dot, erase from the dot. Otherwise, erase trailing zeros
        if (last == dot)
        {
            s.erase(dot);
        }
        else if (last != string::npos)
        {
            s.erase(last + 1);
        }
    }
    return s;
}

class DISPLAY_Statement_Executor : public Statement_Executor
{
private:
    NUMBER _constant_number = 0;
    TEXT _constant_string = "";
    NUMBER *_numeric_value = NULL;
    TEXT *_text_value = NULL;
    unsigned int type = 0;

public:
    DISPLAY_Statement_Executor(NUMBER constant_number)
    {
        _constant_number = constant_number;
        type = 0;
    }

    DISPLAY_Statement_Executor(TEXT constant_string)
    {
        _constant_string = constant_string;
        type = 1;
    }

    DISPLAY_Statement_Executor(NUMBER *number_var)
    {
        _numeric_value = number_var;
        type = 2;
    }

    DISPLAY_Statement_Executor(TEXT *text_var)
    {
        _text_value = text_var;
        type = 3;
    }

    void execute(size_t *program_counter) override
    {
        if (type == 0)
        {
            cout << fix_number(_constant_number) << flush;
        }
        else if (type == 1)
        {
            cout << _constant_string << flush;
        }
        else if (type == 2)
        {
            cout << fix_number(*_numeric_value) << flush;
        }
        else if (type == 3)
        {
            cout << (*_text_value) << flush;
        }
    }
};