//       _    ___  ___ _    ___ _ _
//     | |  |   \| _ \ |  |_  ) | |
//    | |__| |) |  _/ |__ / /|_  _|
//   |____|___/|_| |____/___| |_|
// -= LDPL's Great Leap Backwards =-

// TODO:
// Documentar stdlib
// Hacer que si recibe - por parémtro ejecute el código que recibe por stdin
// Hacer que \n ponga un salto de linea porque sino no hay forma de guardar un string con linebreaks
// Ver si aclare como se inicializan por default las variables
// Documentar secuencias de escape

#include "ldpl.h"
ldpl_compilation_state state;  // Compiler state (holds variables, sections, functions, etc)
LDPL_Execution_State ex_state; // Execution State

int main(int argc, const char *argv[])
{
    // Get command line arguments as string vector
    vector<string> args(argv + 1, argv + argc);
    if (args.size() == 1 && (args[0] == "-v" || args[0] == "--version"))
    {
        displayVersionInfo();
        return 0;
    }
    else if (args.size() == 1 && (args[0] == "-h" || args[0] == "--help"))
    {
        cout << "Usage: ldpl [options] file [arguments]" << endl;
        cout << "Options:" << endl;
        cout << "  -h --help                Display this information" << endl;
        cout << "  -i=<file>                Include file in current compilation" << endl;
        cout << "  -v --version             Display LDPL version information" << endl;
        return 0;
    }

    // state.variables["ARGC"] = 1;
    // state.variables["ARGV"] = 4;
    bool arguments_are_arguments = false;
    int argument_push_count = 0;
    vector<string> files_to_compile;

    // Check arguments
    if (args.size() >= 1)
    {
        for (string &arg : args)
        {
            if (!arguments_are_arguments)
            {
                if (arg.size() > 1 && arg[0] != '-')
                {
                    files_to_compile.push_back(arg);
                    arguments_are_arguments = true;
                }
                else if (arg.substr(0, 3) == "-i=")
                {
                    files_to_compile.push_back(arg.substr(3));
                }
            }
            else
            {
                // TODO CL Arguments
                // state.add_code("\"" + arg + "\"");
                // state.add_code("TOAUX:ARGV:" + to_string(argument_push_count));
                ++argument_push_count;
            }
        }
    }

    // state.add_code(to_string(argument_push_count));
    // state.add_code("TOAUX:ARGC");

    // Fail if file was not passed
    if (files_to_compile.size() == 0)
        error("Filename expected.");

    // For each file, compile each file into one big code
    for (string &filename : files_to_compile)
    {
        // If it's an argument
        if (filename[0] == '-')
            continue;
        // Reset state section for this file
        state.current_file = filename;
        load_and_compile(filename, state);
    }
    // Run the compiled code
    ex_state.execute();
}

void displayVersionInfo()
{
    // -- Displays LDPL Version Information --
    cout << endl
         << " This is LDPL version " << VERSION
         << endl
         << endl
         << " Copyright (c) 2018 - 2024 by Lartu (www.lartu.net)." << endl
         << " Built with amazing contributions from Chris West, Damián Garro" << endl
         << " and other wonderful contributors." << endl
         << endl
         << " The LDPL Home Page can be found at  mwww.ldpl-lang.org." << endl
         << " The LDPL source code is available at www.github.com/lartu/ldpl." << endl
         << endl
         << " Complete documentation for LDPL should be found on this system"
         << endl
         << " using 'man ldpl'. If you have access to the internet, the"
         << endl
         << " documentation can also be found online at docs.ldpl-lang.org."
         << endl
         << endl
         << " LDPL may be copied only under the terms of the Apache License"
         << endl
         << " Version 2.0, which may be found in the LDPL repository."
         << endl
         << endl;
}

void load_and_compile(string &filename, ldpl_compilation_state &state)
{
    // Load file
    ifstream file(filename);
    // Fail if the file couldn't be loaded
    if (!file.is_open())
        error("The file '" + filename + "' couldn't be opened.");
    // Get file contents
    vector<string> lines;
    string line = "";
    while (getline(file, line))
    {
        replace_whitespace(line);
        lines.push_back(line);
    }
    compile(lines, state);
}

// Replace all whitespace within string
void replace_whitespace(string &code)
{
    for (char &c : code)
    {
        if (isspace(c))
        {
            c = ' ';
        }
    }
}

// Shows error message and exits
void error(const string &msg, const string &file_name, int line_number)
{
    cerr << "LDPL Error!" << endl;
    cerr << msg << endl;
    if (file_name != "")
    {
        cerr << "- In file: " << file_name;
        cerr << endl;
    }
    if (line_number >= 0)
    {
        cerr << "- Line number: " << line_number;
        cerr << endl;
    }
    exit(1);
}

// Compilation process
void compile(vector<string> &lines, ldpl_compilation_state &state)
{
    // For each line in the source code
    for (unsigned int line_num = 0; line_num < lines.size(); ++line_num)
    {
        string &line = lines[line_num];
        trim(line);
        // Split line in various tokens
        vector<string> tokens;
        tokenize(line, line_num, tokens, state.current_file);
        capitalize_tokens(tokens);
        if (tokens.size() == 0)
            continue;
        // TODO: pasar tokens que no sean strings a uppercase
        compile_line(tokens, line_num, state);
    }
    // TODO: si llega acá y hay ifs sin cerrar o procedures sin cerrar, te comés puteada
}

// Tokenizes a line
void tokenize(string &line, unsigned int line_num, vector<string> &tokens, string &current_file)
{
    bool in_string = false;
    string current_token = "";
    // For each letter in the line
    for (unsigned int i = 0; i < line.size(); ++i)
    {
        char letter = line[i];
        if (letter == ' ')
        {
            if (in_string)
                current_token += letter;
            else
            {
                if (current_token.size() > 0)
                    tokens.push_back(current_token);
                current_token = "";
            }
        }
        else if (letter == '"')
        {
            in_string = !in_string;
            current_token += letter;
        }
        else if (letter == '\\')
        {
            if (i < line.size() - 1)
            {
                char next_letter = line[++i];
                if (next_letter == '\\' || next_letter == '"')
                    current_token += next_letter;
                else if (next_letter == 'a')
                    current_token += '\a';
                else if (next_letter == 'b')
                    current_token += '\b';
                else if (next_letter == 't')
                    current_token += '\t';
                else if (next_letter == 'n')
                    current_token += '\n';
                else if (next_letter == 'v')
                    current_token += '\v';
                else if (next_letter == 'f')
                    current_token += '\f';
                else if (next_letter == 'r')
                    current_token += '\r';
                else if (next_letter == 'e')
                    current_token += '\e';
                else if (next_letter == '0')
                    current_token += '\0';
                else
                    error("unknown escape sequence (" + current_file + ", line " + to_string(line_num) + ")");
            }
            else
                error("\\ found alone (" + current_file + ", line " + to_string(line_num) + ")");
        }
        else if (letter == '#') // Comment character
        {
            if (in_string)
                current_token += letter;
            else
            {
                if (current_token.size() > 0)
                    tokens.push_back(current_token);
                return;
            }
        }
        else
        {
            current_token += letter;
        }
        if (i == line.size() - 1 && letter != ' ')
        {
            if (in_string)
                error("Unterminated string (" + current_file + ", line " + to_string(line_num) + ")");
            if (current_token.size() > 0)
                tokens.push_back(current_token);
        }
    }
}

// Tokens to upper case
void capitalize_tokens(vector<string> &tokens)
{
    for (string &token : tokens)
    {
        if (!is_number(token) && !is_string(token))
        {
            for (char &l : token)
            {
                l = toupper(l);
            }
        }
    }
}

// Compiles line per line
void compile_line(vector<string> &tokens, unsigned int line_num, ldpl_compilation_state &state)
{
    string &current_file = state.current_file;
    ++line_num;

    // +-------------------+
    // | IS NUMBER Command |
    // +-------------------+-------------------------------------------------------------------------------------------
    if (line_like("$name IS NUMBER", tokens, state))
    {
        string var_id = tokens[0];
        if (!state.variable_exists(var_id))
        {
            state.add_variable(var_id, NUMBER_TYPE);
            ex_state.AddNumberVariable(var_id);
        }
        else
        {
            error("Duplicate declaration for variable '" + var_id + "'.", current_file, line_num);
        }
        return;
    }

    // +-----------------+
    // | IS TEXT Command |
    // +-----------------+---------------------------------------------------------------------------------------------
    if (line_like("$name IS TEXT", tokens, state))
    {
        string var_id = tokens[0];
        if (!state.variable_exists(var_id))
        {
            state.add_variable(var_id, TEXT_TYPE);
            ex_state.AddTextVariable(var_id);
        }
        else
        {
            error("Duplicate declaration for variable '" + var_id + "'.", current_file, line_num);
        }
        return;
    }

    // +-----------------+
    // | DISPLAY Command |
    // +-----------------+---------------------------------------------------------------------------------------------
    if (line_like("DISPLAY $display", tokens, state))
    {
        for (unsigned int i = 1; i < tokens.size(); ++i)
        {
            DISPLAY_Statement_Executor *executor = NULL;
            string token = tokens[i];
            if (token == "CRLF")
            {
                executor = new DISPLAY_Statement_Executor("\r\n");
            }
            else if (state.variable_exists(token))
            {
                if (state.is_num_var(token))
                {
                    executor = new DISPLAY_Statement_Executor(ex_state.GetNumberVariable(token));
                }
                else
                {
                    executor = new DISPLAY_Statement_Executor(ex_state.GetTextVariable(token));
                }
            }
            else
            {
                if (is_number(token))
                {
                    executor = new DISPLAY_Statement_Executor(stod(token));
                }
                else
                {
                    executor = new DISPLAY_Statement_Executor(prepare_string(token));
                }
            }
            ex_state.AddExecutor(executor);
        }
        return;
    }

    // +------------------------+
    // | STORE (Number) Command |
    // +------------------------+--------------------------------------------------------------------------------------
    if (line_like("STORE $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand))
        {
            constant_value = stod(first_operand);
        }
        else
        {
            first_var = ex_state.GetNumberVariable(first_operand);
        }
        STORE_NUM_Statement_Executor *executor = new STORE_NUM_Statement_Executor(first_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +-------------+
    // | ADD Command |
    // +-------------+-------------------------------------------------------------------------------------------------
    if (line_like("ADD $number AND $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        string first_operand = tokens[1];
        string second_operand = tokens[3];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER *second_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand) && is_number(second_operand))
        {
            constant_value = stod(first_operand) + stod(second_operand);
        }
        else
        {
            if (is_number(first_operand))
            {
                constant_value = stod(first_operand);
            }
            else
            {
                first_var = ex_state.GetNumberVariable(first_operand);
            }
            if (is_number(second_operand))
            {
                constant_value = stod(second_operand);
            }
            else
            {
                second_var = ex_state.GetNumberVariable(second_operand);
            }
        }
        ADD_Statement_Executor *executor = new ADD_Statement_Executor(first_var, second_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +------------------+
    // | SUBTRACT Command |
    // +------------------+--------------------------------------------------------------------------------------------
    if (line_like("SUBTRACT $number FROM $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        string first_operand = tokens[1];
        string second_operand = tokens[3];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER *second_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand) && is_number(second_operand))
        {
            constant_value = stod(second_operand) - stod(first_operand);
        }
        else
        {
            if (is_number(first_operand))
            {
                constant_value = stod(first_operand);
            }
            else
            {
                first_var = ex_state.GetNumberVariable(first_operand);
            }
            if (is_number(second_operand))
            {
                constant_value = stod(second_operand);
            }
            else
            {
                second_var = ex_state.GetNumberVariable(second_operand);
            }
        }
        SUBTRACT_Statement_Executor *executor = new SUBTRACT_Statement_Executor(first_var, second_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +----------------+
    // | DIVIDE Command |
    // +----------------+----------------------------------------------------------------------------------------------
    if (line_like("DIVIDE $number BY $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        string first_operand = tokens[1];
        string second_operand = tokens[3];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER *second_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand) && is_number(second_operand))
        {
            constant_value = stod(first_operand) / stod(second_operand);
        }
        else
        {
            if (is_number(first_operand))
            {
                constant_value = stod(first_operand);
            }
            else
            {
                first_var = ex_state.GetNumberVariable(first_operand);
            }
            if (is_number(second_operand))
            {
                constant_value = stod(second_operand);
            }
            else
            {
                second_var = ex_state.GetNumberVariable(second_operand);
            }
        }
        DIVIDE_Statement_Executor *executor = new DIVIDE_Statement_Executor(first_var, second_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +------------------+
    // | MULTIPLY Command |
    // +------------------+--------------------------------------------------------------------------------------------
    if (line_like("MULTIPLY $number BY $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        string first_operand = tokens[1];
        string second_operand = tokens[3];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER *second_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand) && is_number(second_operand))
        {
            constant_value = stod(first_operand) * stod(second_operand);
        }
        else
        {
            if (is_number(first_operand))
            {
                constant_value = stod(first_operand);
            }
            else
            {
                first_var = ex_state.GetNumberVariable(first_operand);
            }
            if (is_number(second_operand))
            {
                constant_value = stod(second_operand);
            }
            else
            {
                second_var = ex_state.GetNumberVariable(second_operand);
            }
        }
        MULTIPLY_Statement_Executor *executor = new MULTIPLY_Statement_Executor(first_var, second_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +----------------+
    // | MODULO Command |
    // +----------------+----------------------------------------------------------------------------------------------
    if (line_like("MODULO $number BY $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        string first_operand = tokens[1];
        string second_operand = tokens[3];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER *second_var = NULL;
        int constant_value = 0;
        if (is_number(first_operand) && is_number(second_operand))
        {
            int value1 = stod(first_operand);
            int value2 = stod(second_operand);
            constant_value = value1 % value2;
        }
        else
        {
            if (is_number(first_operand))
            {
                constant_value = stod(first_operand);
            }
            else
            {
                first_var = ex_state.GetNumberVariable(first_operand);
            }
            if (is_number(second_operand))
            {
                constant_value = stod(second_operand);
            }
            else
            {
                second_var = ex_state.GetNumberVariable(second_operand);
            }
        }
        MODULO_Statement_Executor *executor = new MODULO_Statement_Executor(first_var, second_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +---------------+
    // | LABEL Command |
    // +---------------+-----------------------------------------------------------------------------------------------
    if (line_like("LABEL $name", tokens, state))
    {
        string label_id = tokens[1];
        if (!state.add_label(label_id))
        {
            error("Duplicate label '" + label_id + "'.", current_file, line_num);
        }
        else
        {
            // Label added correctly
            ex_state.AddLabel(label_id);
        }
        return;
    }

    // +---------------+
    // | GO TO Command |
    // +---------------+-----------------------------------------------------------------------------------------------
    if (line_like("GO TO $name", tokens, state))
    {
        string label_id = tokens[2];
        if (!state.label_exists(label_id))
        {
            error("Label not found '" + label_id + "'.", current_file, line_num);
        }
        else
        {
            // Label added correctly
            GOTO_Statement_Executor *executor = new GOTO_Statement_Executor(ex_state.GetLabel(label_id));
            ex_state.AddExecutor(executor);
        }
        return;
    }

    // +-------------+
    // | ABS Command |
    // +-------------+-------------------------------------------------------------------------------------------------
    if (line_like("ABS $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand))
        {
            constant_value = stod(first_operand);
        }
        else
        {
            first_var = ex_state.GetNumberVariable(first_operand);
        }
        ABS_Statement_Executor *executor = new ABS_Statement_Executor(first_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +--------------+
    // | CEIL Command |
    // +--------------+------------------------------------------------------------------------------------------------
    if (line_like("CEIL $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand))
        {
            constant_value = stod(first_operand);
        }
        else
        {
            first_var = ex_state.GetNumberVariable(first_operand);
        }
        CEIL_Statement_Executor *executor = new CEIL_Statement_Executor(first_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +---------------+
    // | FLOOR Command |
    // +---------------+-----------------------------------------------------------------------------------------------
    if (line_like("FLOOR $number IN $num-var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        NUMBER *destination_var = ex_state.GetNumberVariable(dest_var_id);
        NUMBER *first_var = NULL;
        NUMBER constant_value = 0;
        if (is_number(first_operand))
        {
            constant_value = stod(first_operand);
        }
        else
        {
            first_var = ex_state.GetNumberVariable(first_operand);
        }
        FLOOR_Statement_Executor *executor = new FLOOR_Statement_Executor(first_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +----------------+
    // | ACCEPT Command |
    // +----------------+----------------------------------------------------------------------------------------------
    if (line_like("ACCEPT $text IN $var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        NUMBER *destination_number = NULL;
        TEXT *destination_text = NULL;
        TEXT prompt = "> ";
        TEXT *prompt_var = NULL;
        // Get prompt
        if (is_string(first_operand))
        {
            prompt = prepare_string(first_operand);
        }
        else
        {
            prompt_var = ex_state.GetTextVariable(first_operand);
        }
        // TEXT VARIABLE case
        if (state.is_txt_var(dest_var_id))
        {
            destination_text = ex_state.GetTextVariable(dest_var_id);
        }
        // NUMBER VARIABLE case
        else if (state.is_num_var(dest_var_id))
        {
            destination_number = ex_state.GetNumberVariable(dest_var_id);
        }
        ACCEPT_Statement_Executor *executor = new ACCEPT_Statement_Executor(destination_number, destination_text, prompt, prompt_var);
        ex_state.AddExecutor(executor);
        return;
    }

    // +----------------------+
    // | STORE (Text) Command |
    // +----------------------+----------------------------------------------------------------------------------------
    if (line_like("STORE $text IN $str-var", tokens, state))
    {
        string dest_var_id = tokens[3];
        string first_operand = tokens[1];
        TEXT *destination_var = ex_state.GetTextVariable(dest_var_id);
        TEXT *first_var = NULL;
        TEXT constant_value = "";
        if (is_string(first_operand))
        {
            constant_value = prepare_string(first_operand);
        }
        else
        {
            first_var = ex_state.GetTextVariable(first_operand);
        }
        STORE_TEXT_Statement_Executor *executor = new STORE_TEXT_Statement_Executor(first_var, constant_value, destination_var);
        ex_state.AddExecutor(executor);
        return;
    }

    if (line_like("JOIN $text AND $text IN $str-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        return;
    }
    if (line_like("GET CHARACTER AT $number FROM $text IN $str-var", tokens, state))
    {
        string dest_var_id = tokens[7];
        return;
    }
    if (line_like("GET LENGTH OF $text IN $str-var", tokens, state))
    {
        string dest_var_id = tokens[5];
        return;
    }
    if (line_like("SUB-PROCEDURE $name", tokens, state))
    {
        string sub_id = tokens[1];
        if (state.in_subprocedure())
        {
            error("Sub-procedure declared inside another sub-procedure.", current_file, line_num);
        }
        if (state.open_subprocedure(sub_id))
        {
            // TODO
        }
        else
        {
            // Subprocedure already existed
            error("Duplicate declaration for sub-procedure '" + sub_id + "'.", current_file, line_num);
        }
    }
    if (line_like("RETURN", tokens, state))
    {
        if (!state.in_subprocedure())
        {
            // Return found outside SUB-PROCEDURE
            error("RETURN command found outside a sub-procedure.", current_file, line_num);
        }
        return;
    }
    if (line_like("END SUB-PROCEDURE", tokens, state))
    {
        if (!state.in_subprocedure())
        {
            // ENDSUB outside SUB
            error("END SUB-PROCEDURE command found outside a sub-procedure.", current_file, line_num);
        }
        else
        {
            state.close_subprocedure();
        }
        return;
    }
    if (line_like("IF $condition THEN", tokens, state))
    {
        int if_num = state.add_if();
        return;
    }
    if (line_like("ELSE", tokens, state))
    {
        // int ifNum = state.if_stack.top();
        // state.if_stack.pop();
        return;
    }
    if (line_like("END IF", tokens, state) || line_like("END-IF", tokens, state))
    {
        /*if (state.if_stack.size() == 0)
        {
            error("END IF without IF (" + current_file + ", line " + to_string(line_num) + ")");
        }*/
        /*// NVM
        int ifNum = state.if_stack.top();
        state.if_stack.pop();
        // Si no tenía ELSE
        if (state.if_stack.size() > 0 && state.if_stack.top() == ifNum)
        {
            state.if_stack.pop();
            state.add_code("@else" + to_string(ifNum));
        }
        state.add_code("@endif" + to_string(ifNum));*/
        return;
    }

    if (line_like("WHILE $condition DO", tokens, state))
    {
        int while_num = state.add_while();
        return;
    }
    if (line_like("REPEAT", tokens, state))
    {
        /*if (state.while_stack.size() == 0)
        {
            error("REPEAT called without a preceding WHILE.", current_file, line_num);
        }
        int while_num = state.while_stack.top();
        state.while_stack.pop();*/
        return;
    }
    if (line_like("BREAK", tokens, state))
    {
        /*if (state.while_stack.size() == 0)
        {
            error("BREAK called outside a WHILE.", current_file, line_num);
        }
        int while_num = state.while_stack.top();*/
        return;
    }
    if (line_like("CONTINUE", tokens, state))
    {
        /*if (state.while_stack.size() == 0)
        {
            error("CONTINUE called outside a WHILE.", current_file, line_num);
        }
        int while_num = state.while_stack.top();*/
        return;
    }

    if (line_like("CALL SUB-PROCEDURE $subprocedure", tokens, state))
    {
        string sub_id = tokens[2];
        return;
    }
    error("The line is malformed or contains some errors.", current_file, line_num);
}

// Check if the tokens of a line passed are like the ones of a model line
bool line_like(string model_line, vector<string> tokens, ldpl_compilation_state &state)
{
    // Tokenize model line
    vector<string> model_tokens;
    tokenize(model_line, 0, model_tokens, state.current_file);
    // Check that tokens match between line and model line
    if (tokens.size() < model_tokens.size())
    {
        return false;
    }
    unsigned int i = 0;
    for (; i < model_tokens.size(); ++i)
    {
        if (model_tokens[i] == "$name") //$name is any word that is not a string or a number
        {
            if (is_string(tokens[i]))
                return false;
            if (is_number(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$num-var") //$num-var is NUMBER variable
        {
            if (!state.is_num_var(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$str-var") //$str-var is TEXT variable
        {
            if (!state.is_txt_var(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$var") //$num-var is NUMBER or TEXT variable
        {
            if (!state.is_num_var(tokens[i]) && !state.is_txt_var(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$text") //$text is a string value (constant or variable)
        {
            if (!is_string(tokens[i]) && !state.is_txt_var(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$number") //$number is a numeric value (constant or variable)
        {
            if (!is_number(tokens[i]) && !state.is_num_var(tokens[i]))
                return false;
        }
        else if (model_tokens[i] == "$display") // multiple NUMBER, TEXT, TEXT-VAR, NUMBER-VAR or CRLF
        {
            for (; i < tokens.size(); ++i)
            {
                if (!is_string(tokens[i]) && !is_number(tokens[i]) && !state.variable_exists(tokens[i]) && tokens[i] != "CRLF")
                    return false;
            }
        }
        else if (model_tokens[i] == "$subprocedure") //$subprocedure is a SUB-PROCEDURE
        {
            if (!state.subprocedure_exists(tokens[i]))
                return false;
        }
        else if (model_tokens[i] != tokens[i])
            return false;
    }
    if (i < tokens.size())
        return false;
    return true;
}

/// @brief Checks if a string represents a valid number.
/// @param number
/// @return True if the string represents a valid number. Otherwise false.
bool is_number(string number)
{
    try
    {
        stod(number);
    }
    catch (const std::invalid_argument &ia)
    {
        return false;
    }
    return true;
}

bool is_string(string &token)
{
    return (token.size() >= 2 && token[0] == '"' && token[token.size() - 1] == '"');
}

string prepare_string(string &str)
{
    return str.substr(1, str.size() - 2);
}