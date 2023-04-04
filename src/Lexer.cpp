#include <string>
#include "Token.h"

class Lexer {
public:
    Lexer(std::string input) : input_(input), position_(0) {}

    Token getNextToken() {
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
                    } else if (isalpha(input_[position_])) { // check for identifier
                        return getIdentifier();
                    }
                    return Token::Invalid;
            }
        }
        return Token::Eof;
    }

    std::string getTokenValue() const { return tokenValue_; }

private:
    Token getNumber() {
        std::string number;
        while (position_ < input_.size() && isdigit(input_[position_])) {
            number.push_back(input_[position_]);
            advance();
        }
        tokenValue_ = number;
        return Token::Number;
    }

    Token getIdentifier() { // get identifier
        std::string identifier;
        while (position_ < input_.size() && isalnum(input_[position_])) {
            identifier.push_back(input_[position_]);
            advance();
        }
        tokenValue_ = identifier;
        return Token::Identifier;
    }

    void advance() { ++position_; }

    std::string input_;
    std::string tokenValue_;
    size_t position_;
};

