#include "Parser.h"
#include "Statement.h"

void Parser::getNextToken() {
    currentToken_ = lexer_.getNextToken();
}

Statement Parser::getNextStatement() {

    return Statement();
}

