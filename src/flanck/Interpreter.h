#ifndef FLANCK_INTERPRETER_H
#define FLANCK_INTERPRETER_H

#include <string>
#include <utility>
#include <unordered_map>
#include "Token.h"
#include "Statement.h"
#include "Parser.h"

class Interpreter
{
public:
    explicit Interpreter(Parser& parser) : parser_(parser), currentStatement_(nullptr) {}
    double interpret();
private:
    Parser &parser_;
    Statement currentStatement_;
};
#endif //FLANCK_INTERPRETER_H
