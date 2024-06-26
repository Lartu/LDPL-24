//STDLib Imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <locale>
#include <cmath>
#include <map>
#include <cctype>

// LDPL Imports
#include "cpptrim.h"
#include "state.cpp"

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
string prepare_string(string &str);
void capitalize_tokens(vector<string> &tokens);
void load_and_compile(string &filename, ldpl_compilation_state &state);
void replace_whitespace(string &code);
void displayVersionInfo();

// Executors
#include "executors/add.cpp"
#include "executors/subtract.cpp"
#include "executors/divide.cpp"
#include "executors/multiply.cpp"
#include "executors/modulo.cpp"
#include "executors/store_num.cpp"
#include "executors/display.cpp"
#include "executors/goto.cpp"
#include "executors/abs.cpp"
#include "executors/ceil.cpp"
#include "executors/floor.cpp"
#include "executors/accept.cpp"
#include "executors/store_text.cpp"
#include "executors/join.cpp"
#include "executors/get_length.cpp"
#include "executors/slice.cpp"
#include "executors/call.cpp"
#include "executors/return.cpp"