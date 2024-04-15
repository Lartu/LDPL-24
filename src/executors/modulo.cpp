#include "../state.cpp"

class MODULO_Statement_Executor : public Statement_Executor
{
private:
    int _constant = 0;
    NUMBER *_operand_1 = NULL;
    NUMBER *_operand_2 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    MODULO_Statement_Executor(NUMBER *operand_1, NUMBER *operand_2, int constant, NUMBER *destination)
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
            int integer_value1 = *_operand_1;
            *_destination = integer_value1 % _constant;
        }
        else if (type == 2)
        {
            int integer_value2 = *_operand_2;
            *_destination = _constant % integer_value2;
        }
        else if (type == 3)
        {
            int integer_value1 = *_operand_1;
            int integer_value2 = *_operand_2;
            *_destination = integer_value1 % integer_value2;
        }
    }
};