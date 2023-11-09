#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>

class ExpressionManager {
public:
    // Check if the parentheses in the expression are balanced
    static bool isBalancedParentheses(const std::string& expression);

    // Convert an infix expression to a postfix expression
    static std::string infixToPostfix(const std::string& infixExpr);

    // Check if a character is an operator (+, -, *, /, %)
    static bool isOperator(char c);

    // Get the precedence of an operator
    static int getPrecedence(char op);
};

#endif
