#ifndef LDPL_STATE
#define LDPL_STATE 1
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

#define var_type unsigned int
#define NUMBER_TYPE 1
#define TEXT_TYPE 2
#define NUMBER double
#define TEXT string

class ldpl_compilation_state
{
private:
    string current_subprocedure = "";
    set<string> subprocedures;
    map<string, var_type> variables;
    stack<string> working_dir;
    unsigned int current_line = 0;
    int if_number = 0;
    stack<int> if_stack;
    int while_number = 0;
    stack<int> while_stack;
    set<string> labels;

public:
    string current_file = "";
    int add_if()
    {
        ++if_number;
        if_stack.push(if_number);
        if_stack.push(if_number);
        return if_number;
    }
    int add_while()
    {
        ++while_number;
        while_stack.push(while_number);
        return while_number;
    }
    bool subprocedure_exists(string &token)
    {
        return subprocedures.count(token) > 0;
    }
    bool in_subprocedure()
    {
        return current_subprocedure == "";
    }
    bool open_subprocedure(string &id)
    {
        if (!subprocedure_exists(id))
        {
            current_subprocedure = id;
            subprocedures.insert(id);
            return true;
        }
        else
        {
            return false;
        }
    }
    void close_subprocedure()
    {
        current_subprocedure = "";
    }
    bool is_num_var(string &token)
    {
        return variables.count(token) > 0 && variables[token] == NUMBER_TYPE;
    }
    bool is_txt_var(string &token)
    {
        return variables.count(token) > 0 && variables[token] == TEXT_TYPE;
    }

    bool variable_exists(string &token)
    {
        return is_num_var(token) || is_txt_var(token);
    }

    /// @brief Adds a variable of the given state to the LDPL State.
    /// @return True if the variable was added correctly. False otherwise.
    bool add_variable(string &id, var_type type)
    {
        if (!variable_exists(id))
        {
            variables[id] = type;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool label_exists(string &id)
    {
        return labels.count(id) > 0;
    }

    bool add_label(string &id)
    {
        if (!label_exists(id))
        {
            labels.insert(id);
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Statement_Executor
{
public:
    virtual void execute(size_t *program_counter)
    {
        cout << "An empty executor is being executed. This is a bug, please report it!" << endl;
    }
};

class LDPL_Execution_State
{
private:
    map<string, NUMBER> number_variables;
    map<string, TEXT> text_variables;
    map<string, size_t> labels;
    vector<Statement_Executor *> program;

public:
    void AddLabel(string &id)
    {
        labels[id] = program.size();
    }

    size_t GetLabel(string &id)
    {
        return labels[id];
    }

    NUMBER *GetNumberVariable(string &id)
    {
        return &(number_variables[id]);
    }

    TEXT *GetTextVariable(string &id)
    {
        return &(text_variables[id]);
    }

    void AddNumberVariable(string &id)
    {
        number_variables[id] = 0;
    }

    void AddTextVariable(string &id)
    {
        text_variables[id] = "";
    }

    void AddExecutor(Statement_Executor *se)
    {
        program.push_back(se);
    }

    void execute()
    {
        // Clear unused structures
        labels.clear();

        // Run program
        size_t program_counter = 0;
        while (program_counter < program.size())
        {
            (*program[program_counter]).execute(&program_counter);
            program_counter++;
        }
    }
};
#endif