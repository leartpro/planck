#ifndef PLANCK_INTERPRETER_H
#define PLANCK_INTERPRETER_H

#include <string>
#include <utility>
#include <unordered_map>
#include "Token.h"
#include "AST.h"

class Interpreter
{
public:
    Interpreter() = default;
    double interpret(AstNode* root);
    void setVariable(const string& name, double value);
private:
    unordered_map<std::string, double> variables_;
};
#endif //PLANCK_INTERPRETER_H
