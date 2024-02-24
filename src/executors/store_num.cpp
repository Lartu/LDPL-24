#include "../state.cpp"

class STORE_NUM_Statement_Executor : public Statement_Executor
{
private:
    NUMBER _constant = 0;
    NUMBER *_operand_1 = NULL;
    NUMBER *_destination = NULL;
    unsigned int type = 0;

public:
    STORE_NUM_Statement_Executor(NUMBER *operand_1, NUMBER constant, NUMBER *destination)
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