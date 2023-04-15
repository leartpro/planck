#include "Lexer.h"

using namespace std;

Token Lexer::getNextToken() {
    while (position_ < input_.size()) {
        switch (input_[position_]) {
            case '[':
                ++position_;
                return Token::Open;
            case ']':
                ++position_;
                return Token::Close;
            case '0':
            case '1':
                return getValue();
            case ':':
                ++position_;
                return Token::Divider;
            default:
                ++position_;
                continue;
        }
    }
    return Token::Eof;
}

string Lexer::getTokenValue() {
    return tokenValue_;
}

Token Lexer::getValue() {
    string value;
    while (position_ < input_.size() && (input_[position_] == '0' || input_[position_] == '1')) {
        value.push_back(input_[position_]);
        ++position_;
    }
    tokenValue_ = value;
    return Token::Value;
}