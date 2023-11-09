#include <iostream>
#include "ExpressionManager.h"
#include "queue.h"

using namespace std;

int main() {
    while (true) {
        try {
            string infixExpression;

            // Read an infix expression from the user
            cout << "Enter an infix expression (or type 'exit' to quit): ";
            cin >> infixExpression;

            // Check if the user wants to exit
            if (infixExpression == "exit") {
                break;
            }

            // Check for balanced parentheses
            if (ExpressionManager::isBalancedParentheses(infixExpression)) {
                // Convert infix to postfix and print the result
                string postfixExpression = ExpressionManager::infixToPostfix(infixExpression);
                if (postfixExpression.find("Invalid expression") == string::npos) {
                    cout << "Postfix expression: " << postfixExpression << endl;
                }
                else {
                    cout << postfixExpression << endl;
                }
            }
            else {
                cout << "Invalid expression (unmatched parentheses)" << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    //For Question 2 relating to Queue
 
    // Create a queue of integers
    cout << endl;
    cout << "TESTING QUEUE FOR INTERGERS" << endl;
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    // Test front
    if (!intQueue.isEmpty()) {
        cout << "Front element (int): " << intQueue.front() << endl;
    }

    // Test dequeue
    while (!intQueue.isEmpty()) {
        intQueue.dequeue();
    }

    // Try to dequeue from an empty queue
    intQueue.dequeue();

    // Test size
    cout << "Queue size (int): " << intQueue.size() << endl;

    // Test isEmpty
    cout << "Is queue empty? (int): " << (intQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "TESTING QUEUE FOR DOUBLES" << endl;
    // Create a queue of doubles
    Queue<double> doubleQueue;
    doubleQueue.enqueue(3.14);
    doubleQueue.enqueue(2.718);

    // Test front
    if (!doubleQueue.isEmpty()) {
        cout << "Front element (float): " << doubleQueue.front() << endl;
    }

    // Test dequeue
    while (!doubleQueue.isEmpty()) {
        doubleQueue.dequeue();
    }

    // Try to dequeue from an empty queue
    doubleQueue.dequeue();

    // Test size
    cout << "Queue size (float): " << doubleQueue.size() << endl;

    // Test isEmpty
    cout << "Is queue empty? (float): " << (doubleQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "TESTING QUEUE FOR CHARACTERS" << endl;
    // Create a queue of characters
    Queue<char> charQueue;
    charQueue.enqueue('A');
    charQueue.enqueue('B');

    // Test front
    if (!charQueue.isEmpty()) {
        cout << "Front element (char): " << charQueue.front() << endl;
    }

    // Test dequeue
    while (!charQueue.isEmpty()) {
        charQueue.dequeue();
    }

    // Try to dequeue from an empty queue
    charQueue.dequeue();

    // Test size
    cout << "Queue size (char): " << charQueue.size() << endl;

    // Test isEmpty
    cout << "Is queue empty? (char): " << (charQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << endl;
    cout << "TESTING QUEUE FOR STRINGS" << endl;
    // Create a queue of strings
    Queue<string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");

    // Test front
    if (!stringQueue.isEmpty()) {
        cout << "Front element (string): " << stringQueue.front() << endl;
    }

    // Test dequeue
    while (!stringQueue.isEmpty()) {
        stringQueue.dequeue();
    }

    // Try to dequeue from an empty queue
    stringQueue.dequeue();

    // Test size
    cout << "Queue size (string): " << stringQueue.size() << endl;

    // Test isEmpty
    cout << "Is queue empty? (string): " << (stringQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
