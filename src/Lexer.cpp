#include "Lexer.h"

using namespace std;

Token Lexer::getNextToken() {
    while (position_ < input_.size()) {
        switch (input_[position_]) {
            case '+':
                ++position_;
                return Token::Plus;
            case '-':
                ++position_;
                return Token::Minus;
            case '*':
                ++position_;
                return Token::Multiply;
            case '/':
                ++position_;
                return Token::Divide;
            case ' ':
                ++position_;
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

string Lexer::getTokenValue() {
    return tokenValue_;
}

Token Lexer::getNumber() {
    string number;
    while (position_ < input_.size() && isdigit(input_[position_])) {
        number.push_back(input_[position_]);
        ++position_;
    }
    tokenValue_ = number;
    return Token::Number;
}

Token Lexer::getIdentifier() {
    string identifier;
    while (position_ < input_.size() && isalnum(input_[position_])) {
        identifier.push_back(input_[position_]);
        ++position_;
    }
    tokenValue_ = identifier;
    return Token::Identifier;
}