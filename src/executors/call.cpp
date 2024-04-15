#include "../state.cpp"

class CALL_Statement_Executor : public Statement_Executor
{
private:
    size_t _pc_value = 0;

public:
    CALL_Statement_Executor(size_t pc_value)
    { 
        _pc_value = pc_value;
    }

    void execute(size_t *program_counter, LDPL_Execution_State *state) override
    {
        state->RegisterCall();
        *program_counter = _pc_value - 1;
    }
};