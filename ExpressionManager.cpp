#include "ExpressionManager.h"
#include <stack>
#include <cctype>

using namespace std;

//Checks if parentheses are balanced
bool ExpressionManager::isBalancedParentheses(const string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty() || (c == ')' && stack.top() != '(') || (c == '}' && stack.top() != '{') || (c == ']' && stack.top() != '[')) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

//Converts infix to postfix notation
string ExpressionManager::infixToPostfix(const string& infixExpr) {
    stack<char> operatorStack;
    string postfixExpr;

    for (char c : infixExpr) {
        if (isalnum(c)) {
            // Operand: Add to the postfix expression
            postfixExpr += c;
        }
        else if (c == '(') {
            // Opening parenthesis: Push onto the stack
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Closing parenthesis: Pop operators from the stack and add to postfix until an open parenthesis is encountered
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpr += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();  // Pop the open parenthesis
            }
            else {
                return "Invalid expression (unmatched ')')";
            }
        }
        else if (ExpressionManager::isOperator(c)) {
            // Operator: Pop operators from the stack and add to postfix until an operator with lower precedence or an open parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(' && ExpressionManager::getPrecedence(operatorStack.top()) >= ExpressionManager::getPrecedence(c)) {
                postfixExpr += operatorStack.top();
                operatorStack.pop();
            }
            // Push the current operator onto the stack
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(') {
            return "Invalid expression (unmatched '(')";
        }
        postfixExpr += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpr;
}

//Determines if a valid operator
bool ExpressionManager::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

//Determines which operators go first/second
int ExpressionManager::getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}
