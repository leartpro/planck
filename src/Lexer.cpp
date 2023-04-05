#include "Lexer.h"

Token Lexer::getNextToken() {
    while (position_ < input_.size()) {
        switch (input_[position_]) {
            case '+':
                advance();
                return Token::Plus;
            case '-':
                advance();
                return Token::Minus;
            case '*':
                advance();
                return Token::Multiply;
            case '/':
                advance();
                return Token::Divide;
            case ' ':
                advance();
                continue;
            default:
                if (isdigit(input_[position_])) {
                    return getNumber();
                } else if (isalpha(input_[position_])) {
                    return getIdentifier();
                }
                return Token::Invalid;
        }
    }
    return Token::Eof;
}

std::string Lexer::getTokenValue() {
    return tokenValue_;
}

Token Lexer::getNumber() {
    std::string number;
    while (position_ < input_.size() && isdigit(input_[position_])) {
        number.push_back(input_[position_]);
        advance();
    }
    tokenValue_ = number;
    return Token::Number;
}

Token Lexer::getIdentifier() {
    std::string identifier;
    while (position_ < input_.size() && isalnum(input_[position_])) {
        identifier.push_back(input_[position_]);
        advance();
    }
    tokenValue_ = identifier;
    return Token::Identifier;
}

void Lexer::advance() { ++position_; }