#include "../state.cpp"

class GOTO_Statement_Executor : public Statement_Executor
{
private:
    size_t _pc_value = 0;

public:
    GOTO_Statement_Executor(size_t pc_value)
    { 
        _pc_value = pc_value;
    }

    void execute(size_t *program_counter) override
    {
        *program_counter = _pc_value - 1;
    }
};