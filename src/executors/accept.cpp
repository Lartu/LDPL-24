#include "../state.cpp"
#include "../linenoise.hpp"

// Special thanks to DVKT / XVXX for writing most of the code used here.

TEXT RL_INPUT;        // RL-INPUT
TEXT RL_HISTORY_FILE; // RL-HISTORY-FILE

class ACCEPT_Statement_Executor : public Statement_Executor
{
private:
    NUMBER *_destination_number = NULL;
    TEXT *_destination_string = NULL;
    TEXT _prompt = "";
    TEXT *_prompt_var = NULL;
    unsigned int type = 0;

public:
    ACCEPT_Statement_Executor(NUMBER *destination_number, TEXT *destination_string, TEXT &prompt, TEXT *prompt_var)
    {
        _destination_number = destination_number;
        _destination_string = destination_string;
        if (prompt_var == NULL)
        {
            _prompt = prompt;
        }
        else
        {
            _prompt_var = prompt_var;
        }
        if (_destination_string == NULL)
        {
            // ACCEPT number
            type = 0;
        }
        else
        {
            // ACCEPT text
            type = 1;
        }
    }

    void execute(size_t *program_counter) override
    {
    retry:
        linenoise::SetHistoryMaxLen(100);
        string input = RL_INPUT;
        if (_prompt_var == NULL)
        {
            // Constant Prompt
            linenoise::Readline(_prompt.c_str(), input);
        }
        else
        {
            // Variable Prompt
            linenoise::Readline((*_prompt_var).c_str(), input);
        }
        RL_INPUT = input;
        linenoise::AddHistory(RL_INPUT.c_str());

        if (type == 0)
        {
            if (is_number(RL_INPUT))
            {
                *_destination_number = stod(RL_INPUT);
            }
            else
            {
                cout << "Enter a numeric value." << endl;
                goto retry;
            }
        }
        else if (type == 1)
        {
            *_destination_string = RL_INPUT;
        }
    }
};