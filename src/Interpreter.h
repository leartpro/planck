#ifndef PLANCK_INTERPRETER_H
#define PLANCK_INTERPRETER_H

#include <string>
#include <utility>
#include "Token.h"
#include "AST.h"

class Interpreter
{
public:
    Interpreter() = default;
    double interpret(AstNode* root);
private:
};
#endif //PLANCK_INTERPRETER_H
