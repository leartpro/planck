#include "token.h"

using namespace lexer;

Token::Token(int final_state, std::string value, unsigned int line_number) :
    type(determine_token_type(final_state, value)),
    value(value),
    line_number(line_number)
{}

TOKEN Token::determine_token_type(int final_state, std::string &basicString) {
    switch(final_state) {
        case 1:
            return TOK_INT;

        case 3:
            return TOK_REAL;

        case 4:
            return TOK_ADDITIVE_OP;

        case 5:
        case 11:
            return TOK_MULTIPLICATIVE_OP;

        case 7:
            return TOK_RELATIONAL_OP;

        case 8:
            return TOK_EQUALS;

        case 9:
            return TOK_RELATIONAL_OP;

        case 10:
            if(basicString == "var")
                return TOK_VAR;
            if(basicString == "set")
                return TOK_SET;
            if(basicString == "def")
                return TOK_DEF;
            if(basicString == "return")
                return TOK_RETURN;
            if(basicString == "if")
                return TOK_IF;
            if(basicString == "else")
                return TOK_ELSE;
            if(basicString == "while")
                return TOK_WHILE;
            if(basicString == "print")
                return TOK_PRINT;
            if(basicString == "int")
                return TOK_INT_TYPE;
            if(basicString == "real")
                return TOK_REAL_TYPE;
            if(basicString == "bool")
                return TOK_BOOL_TYPE;
            if(basicString == "string")
                return TOK_STRING_TYPE;
            if(basicString == "true" || basicString == "false")
                return TOK_BOOL;
            if(basicString == "and")
                return TOK_MULTIPLICATIVE_OP;
            if(basicString == "or")
                return TOK_ADDITIVE_OP;
            if(basicString == "not")
                return TOK_NOT;
            else return TOK_IDENTIFIER;

        case 14:
        case 16:
            return TOK_COMMENT;

        case 20:
            return TOK_STRING;

        case 21:
            if(basicString == "{")
                return TOK_LEFT_CURLY;
            if(basicString == "}")
                return TOK_RIGHT_CURLY;
            if(basicString == "(")
                return TOK_LEFT_BRACKET;
            if(basicString == ")")
                return TOK_RIGHT_BRACKET;
            if(basicString == ",")
                return TOK_COMMA;
            if(basicString == ";")
                return TOK_SEMICOLON;
            if(basicString == ":")
                return TOK_COLON;

        case 22:
            return TOK_EOF;

        default:
            return TOK_ERROR;
    }
}

Token::Token() = default; // NOLINT(cppcoreguidelines-pro-type-member-init)
