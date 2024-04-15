#include "../state.cpp"

class ABS_Statement_Executor : public Statement_Executor
{
private:
    NUMBER _constant = 0;
    NUMBER *_operand_1 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    ABS_Statement_Executor(NUMBER *operand_1, NUMBER constant, NUMBER *destination)
    {
        _constant = constant;
        _operand_1 = operand_1;
        _destination = destination;
        if (_operand_1 == NULL)
        {
            // ABS(value)
            type = 0;
        }
        else
        {
            // ABS(variable)
            type = 1;
        }
    }

    void execute(size_t *program_counter, LDPL_Execution_State *state) override
    {
        if (type == 0)
        {
            *_destination = _constant >= 0 ? _constant : -_constant;
        }
        else if (type == 1)
        {
            NUMBER value = *_operand_1;
            *_destination = value >= 0 ? value : - value;
        }
    }
};