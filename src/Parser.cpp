#include "Parser.h"

AstNode *Parser::parse() {
    getNextToken();
    return expr();
}

AstNode *Parser::expr() {
    AstNode *left = term();
    while (currentToken_ == Token::Plus || currentToken_ == Token::Minus) {
        Token op = currentToken_;
        getNextToken();

        AstNode *right = term();
        auto *newNode = new AstNode();
        newNode->type = AstNodeType::BinaryOperation;
        newNode->left = left;
        newNode->right = right;
        newNode->op = op;
        left = newNode;
    }

    return left;
}

AstNode *Parser::term() {
    if (currentToken_ == Token::Number) {
        auto *node = new AstNode();
        node->type = AstNodeType::NumberLiteral;
        node->value = stod(lexer_.getTokenValue());
        getNextToken();
        return node;
    } else if (currentToken_ == Token::Identifier) { // check for identifier
        auto *node = new AstNode();
        node->type = AstNodeType::Identifier;
        node->identifier = lexer_.getTokenValue();
        getNextToken();
        return node;
    }
    return nullptr; // invalid term
}

void Parser::getNextToken() {
    currentToken_ = lexer_.getNextToken();
}

