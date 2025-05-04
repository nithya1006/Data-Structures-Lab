//Program to implement Tree ADT using character binary tree
#include <iostream>
#include <queue>
using namespace std;

class BinaryTree {
private:
    struct TreeNode {
        char data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(char value) {
            data = value;
            left = right = nullptr;
        }
    } *root;

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    TreeNode* search(TreeNode* node, char key) {
        if (!node || node->data == key)
            return node;

        TreeNode* leftSearch = search(node->left, key);
        return leftSearch ? leftSearch : search(node->right, key);
    }

public:
    BinaryTree() { root = NULL; }

    void insert(char);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    void searchNode(char);
};

int main() {
    BinaryTree tree;
    int choice;
    char value, key;

    while(true) {
        cout << "\nTree ADT Menu:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder traversal: ";
                tree.preorderTraversal();
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.inorderTraversal();
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.postorderTraversal();
                break;
            case 5:
                cout << "Enter node to search: ";
                cin >> key;
                tree.searchNode(key);
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    };
}

//Function to insert a value in the binary tree using level order
void BinaryTree::insert(char value) {
    TreeNode* newNode = new TreeNode(value);
    if (!root) {
        root = newNode;
        cout << "Inserted " << value << " as root node.\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            cout << "Inserted " << value << " as left child of " << temp->data << "\n";
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            cout << "Inserted " << value << " as right child of " << temp->data << "\n";
            return;
        } else {
            q.push(temp->right);
        }
    }
}

//Function to display the tree elements using preorder traversal
void BinaryTree::preorderTraversal() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    preorder(root);
    cout << endl;
}

//Function to display the tree elements using inorder traversal
void BinaryTree::inorderTraversal() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    inorder(root);
    cout << endl;
}

//Function to display the tree elements using postorder traversal
void BinaryTree::postorderTraversal() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    postorder(root);
    cout << endl;
}

//Function to check if an element exists in the tree
void BinaryTree::searchNode(char key) {
    TreeNode* result = search(root, key);
    if (result)
        cout << "Node " << key << " found in the tree.\n";
    else
        cout << "Node " << key << " not found!\n";
}