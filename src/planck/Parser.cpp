#include "Parser.h"

Node *Parser::parse() {
    getNextToken();
    return expr();
}

Node *Parser::expr() {
    Node *left = term();
    while (currentToken_ == Token::Plus || currentToken_ == Token::Minus) {
        Token op = currentToken_;
        getNextToken();

        Node *right = term();
        auto *newNode = new Node();
        newNode->type = Statement::BinaryOperation;
        newNode->left = left;
        newNode->right = right;
        newNode->op = op;
        left = newNode;
    }

    return left;
}

Node *Parser::term() {
    if (currentToken_ == Token::Number) {
        auto *node = new Node();
        node->type = Statement::NumberLiteral;
        node->value = stod(lexer_.getTokenValue());
        getNextToken();
        return node;
    } else if (currentToken_ == Token::Identifier) { // check for identifier
        auto *node = new Node();
        node->type = Statement::Identifier;
        node->identifier = lexer_.getTokenValue();
        getNextToken();
        return node;
    }
    return nullptr; // invalid term
}

void Parser::getNextToken() {
    currentToken_ = lexer_.getNextToken();
}

