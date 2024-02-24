#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <locale>
#include <map>
#include "cpptrim.h"
#include "state.cpp"
#include "executors/add.cpp"
#include "executors/subtract.cpp"
#include "executors/divide.cpp"
#include "executors/multiply.cpp"
#include "executors/modulo.cpp"
#include "executors/store_num.cpp"
#include "executors/display.cpp"
#include "executors/goto.cpp"

#ifndef VERSION
#define VERSION 0
#endif

using namespace std;

class ldpl_compilation_state;
void error(const string &msg, const string &file_name = "", int line_number = -1);
void compile(vector<string> &lines, ldpl_compilation_state &state);
void tokenize(string &line, unsigned int line_num, vector<string> &tokens, string &current_file);
void compile_line(vector<string> &tokens, unsigned int line_num, ldpl_compilation_state &state);
bool line_like(string model_line, vector<string> tokens, ldpl_compilation_state &state); // Important to pass tokens by copy
bool is_number(string number);
bool is_string(string &token);
void capitalize_tokens(vector<string> &tokens);
void load_and_compile(string &filename, ldpl_compilation_state &state);
void replace_whitespace(string &code);
void displayVersionInfo();