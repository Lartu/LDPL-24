#include "../state.cpp"

class STORE_TEXT_Statement_Executor : public Statement_Executor
{
private:
    TEXT _constant = "";
    TEXT *_operand_1 = NULL;
    TEXT *_destination = NULL;
    unsigned int type = 0;

public:
    STORE_TEXT_Statement_Executor(TEXT *operand_1, TEXT constant, TEXT *destination)
    {
        _constant = constant;
        _operand_1 = operand_1;
        _destination = destination;
        if (_operand_1 == NULL)
        {
            type = 0;
        }
        else if (_operand_1 != NULL)
        {
            type = 1;
        }
    }

    void execute(size_t *program_counter) override
    {
        if (type == 0)
        {
            *_destination = _constant;
        }
        else if (type == 1)
        {
            *_destination = *_operand_1;
        }
    }
};