#include "AST.h"
#include "Lexer.h"

class Parser {
public:
    AstNode* parse() {
        getNextToken();
        return expr();
    }
private:
    AstNode* expr() {
        AstNode* left = term();
        while (currentToken_ == Token::Plus || currentToken_ == Token::Minus) {
            Token op = currentToken_;
            getNextToken();

            AstNode* right = term();
            AstNode* newNode = new AstNode();
            newNode->type = AstNodeType::BinaryOperation;
            newNode->left = left;
            newNode->right = right;
            newNode->op = op;
            left = newNode;
        }

        return left;
    }

    AstNode* term() {
        if (currentToken_ == Token::Number) {
            AstNode* node = new AstNode();
            node->type = AstNodeType::NumberLiteral;
            node->value = std::stod(lexer_.getTokenValue());
            getNextToken();
            return node;
        } else if (currentToken_ == Token::Identifier) { // check for identifier
            AstNode* node = new AstNode();
            node->type = AstNodeType::Identifier;
            node->identifier = lexer_.getTokenValue();
            getNextToken();
            return node;
        }
        return nullptr; // invalid term
    }

    void getNextToken() {
        currentToken_ = lexer_.getNextToken();
    }

    Lexer& lexer_;
    Token currentToken_;
};

