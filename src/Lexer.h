#ifndef PLANCK_LEXER_H
#define PLANCK_LEXER_H

#include <string>
#include <utility>
#include "Token.h"

class Lexer
{
public:
    explicit Lexer(const char* input) : input_(input), position_(0) {}
    Token getNextToken();
    std::string getTokenValue();
private:
    int position_;
    std::string input_;
    std::string tokenValue_;
    Token getNumber();
    Token getIdentifier();
    void advance();
};
#endif //PLANCK_LEXER_H
