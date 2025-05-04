//Program to implement queue ADT using integer singly linked list

#include <iostream>
#include <stdio.h>
using namespace std;

class QueueADT{
    private:
    struct node{
        int data;
        struct node* next;
    }*front, *rear;

    public:
    QueueADT() {
        front=NULL;
        rear=NULL;
    }

    void enqueue(int);
    int dequeue();
    void peek(); 
};

int main() {
    QueueADT queue;
    int choice, value, del;

    while (true) {
        cout << "\nQueue ADT Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                del=queue.dequeue();
                if (del!='0'){
                    cout<<"The dequeued element is " << del << endl;
                }
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Try again\n";
        }
    }

    return 0;
}

//To add an element to the queue (enqueue)
void QueueADT::enqueue(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return;
}

//To remove an element from the queue (dequeue)
int QueueADT::dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return 0;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {  
        rear = NULL;
    }
    return temp->data;
}

//To display front element
void QueueADT::peek() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << front->data << "\n";
}