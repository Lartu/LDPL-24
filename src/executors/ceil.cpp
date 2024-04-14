#include "../state.cpp"

class CEIL_Statement_Executor : public Statement_Executor
{
private:
    NUMBER _constant = 0;
    NUMBER *_operand_1 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    CEIL_Statement_Executor(NUMBER *operand_1, NUMBER constant, NUMBER *destination)
    {
        _constant = constant;
        _operand_1 = operand_1;
        _destination = destination;
        if (_operand_1 == NULL)
        {
            // CEIL(value)
            type = 0;
        }
        else
        {
            // CEIL(variable)
            type = 1;
        }
    }

    void execute(size_t *program_counter) override
    {
        if (type == 0)
        {
            *_destination = ceil(_constant);
        }
        else if (type == 1)
        {
            NUMBER value = *_operand_1;
            *_destination = ceil(value);
        }
    }
};