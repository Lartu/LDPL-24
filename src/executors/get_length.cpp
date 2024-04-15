#include "../state.cpp"

class GETLENGTH_Statement_Executor : public Statement_Executor
{
private:
    TEXT _constant = "";
    TEXT *_operand_1 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    GETLENGTH_Statement_Executor(TEXT *operand_1, TEXT &constant, NUMBER *destination)
    {
        _constant = constant;
        _operand_1 = operand_1;
        _destination = destination;
        if (_operand_1 == NULL)
        {
            // LEN(value)
            type = 0;
        }
        else
        {
            // LEN(variable)
            type = 1;
        }
    }

    void execute(size_t *program_counter) override
    {
        if (type == 0)
        {
            *_destination = get_str_utf8length(_constant);
        }
        else if (type == 1)
        {
            *_destination = get_str_utf8length(*_operand_1);
        }
    }

    size_t get_str_utf8length(const string cstr)
    {
        size_t len = cstr.size();
        size_t utf8len = 0;
        unsigned int c;
        for (size_t i = 0; i < len; i++)
        {
            size_t l = 0;
            c = (unsigned char)cstr[i];
            if (c >= 0 && c <= 127)
                l = 0;
            else if ((c & 0xE0) == 0xC0)
                l = 1;
            else if ((c & 0xF0) == 0xE0)
                l = 2;
            else if ((c & 0xF8) == 0xF0)
                l = 3;
            else if (c >= 248 && c <= 255)
                return 0; // invalid utf8
            i += l;
            utf8len++;
        }
        return utf8len;
    }
};