//Construct expression tree added to binary search tree
#include <iostream>
#include <stack>
#include <cctype>
#include "bst.h"
using namespace std;

int main() {
    BST bst;
    int choice;
    string postfix;
    
    while (true){
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter valid postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                bst.constructTree(postfix);
                break;
            case 3:
                cout << "Preorder: ";
                bst.preorder(bst.root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder: ";
                bst.inorder(bst.root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder: ";
                bst.postorder(bst.root);
                cout << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
    
    return 0;
}

