#include "../state.cpp"

class RETURN_Statement_Executor : public Statement_Executor
{
private:
    size_t _pc_value = 0;

public:
    RETURN_Statement_Executor()
    { 
    }

    void execute(size_t *program_counter, LDPL_Execution_State *state) override
    {
        *program_counter = state->GetCallBack();
    }
};