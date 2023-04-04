#ifndef PLANCK_LEXER_H
#define PLANCK_LEXER_H

#include <string>
#include <utility>
#include "Token.h"

class Lexer
{
public:
    explicit Lexer(std::string input) : input_(std::move(input)), position_(0) {}
    Token getNextToken();
private:
    int position_;
    std::string input_;
    Token getNumber();
    Token getIdentifier();
    void advance();
};
#endif //PLANCK_LEXER_H
