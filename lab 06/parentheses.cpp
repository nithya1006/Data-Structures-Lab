//Program to check whether '(' and ')' are balanced in the given input string 

#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

bool isBalanced(const string &expr);

int main() {
    int choice;
    string expr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout << "Enter the string of parentheses: ";
                cin >> expr;

                if (isBalanced(expr))
                    cout << "The parentheses are balanced.\n";
                else
                    cout << "The parentheses are NOT balanced.\n";
                break;

            case 2:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    }
}

// Function to check if a given string has balanced parentheses
bool isBalanced(const string &expr) {
    StackADT s;
    for (char ch : expr) {
        if (ch == '(') {
            s.Push(ch);
        } else if (ch == ')') {
            if (s.isEmpty()) {
                return false;
            }
            s.Pop();
        }
    }
    return s.isEmpty(); 
}