#ifndef FLANCK_PARSER_H
#define FLANCK_PARSER_H

#include <string>
#include <utility>
#include "Token.h"
#include "Lexer.h"
#include "Statement.h"

class Parser
{
public:
    explicit Parser(Lexer& lexer) : lexer_(lexer), currentToken_(Token::Invalid) {}
    Statement getNextStatement();
private:
    void getNextToken();
    Lexer &lexer_;
    Token currentToken_;
};
#endif //FLANCK_PARSER_H
