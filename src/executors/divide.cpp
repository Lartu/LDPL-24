#include "../state.cpp"

class DIVIDE_Statement_Executor : public Statement_Executor
{
private:
    NUMBER _constant = 0;
    NUMBER *_operand_1 = NULL;
    NUMBER *_operand_2 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    DIVIDE_Statement_Executor(NUMBER *operand_1, NUMBER *operand_2, NUMBER constant, NUMBER *destination)
    {
        _constant = constant;
        _operand_1 = operand_1;
        _operand_2 = operand_2;
        _destination = destination;
        if (_operand_1 == NULL && _operand_2 == NULL)
        {
            type = 0;
        }
        else if (_operand_1 != NULL && _operand_2 == NULL)
        {
            type = 1;
        }
        else if (_operand_1 == NULL && _operand_2 != NULL)
        {
            type = 2;
        }
        else if (_operand_1 != NULL && _operand_2 != NULL)
        {
            type = 3;
        }
    }

    void execute(size_t *program_counter, LDPL_Execution_State *state) override
    {
        if (type == 0)
        {
            *_destination = _constant;
        }
        else if (type == 1)
        {
            *_destination = *_operand_1 / _constant;
        }
        else if (type == 2)
        {
            *_destination = _constant / *_operand_2;
        }
        else if (type == 3)
        {
            *_destination = *_operand_1 / *_operand_2;
        }
    }
};