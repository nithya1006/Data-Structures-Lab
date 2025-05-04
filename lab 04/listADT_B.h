//Header file with listADT using sll
#include <iostream>
#include <cstdlib>
using namespace std;

class ListADT {
private:
    struct Node {
        int data;
        struct Node* next;
    } *head;

    struct Node* gethead() const; 

public:
    ListADT() {head=NULL;};

    void insertAscending(int value);
    void merge(const ListADT& list1, const ListADT& list2);
    void display() const;
};

ListADT::Node* ListADT::gethead() const {
    return head;
}

//Function insert a value to list in ascending order
void ListADT::insertAscending(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* curr = head;
    while (curr->next && curr->next->data < value) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

//Function to merge two lists into a third list
void ListADT::merge(const ListADT& list1, const ListADT& list2) {
    struct Node* l1 = list1.gethead();
    struct Node* l2 = list2.gethead();
    struct Node** lastPtrRef = &head;
    head = nullptr;  // Reset head before merging

    while (l1 && l2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) return;

        if (l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = nullptr;
        *lastPtrRef = newNode;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (l1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) return;
        newNode->data = l1->data;
        newNode->next = nullptr;
        *lastPtrRef = newNode;
        lastPtrRef = &((*lastPtrRef)->next);
        l1 = l1->next;
    }

    while (l2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) return;
        newNode->data = l2->data;
        newNode->next = nullptr;
        *lastPtrRef = newNode;
        lastPtrRef = &((*lastPtrRef)->next);
        l2 = l2->next;
    }
}

//Function to display all the elements in a list
void ListADT::display() const {
    struct Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}