//QueueADT header file for string expression evaluation program

#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Queue{
    private:
    struct node{
        char data;
        struct node* next;
        struct node* prev;
    }*front, *rear;

    public:
    Queue() {
        front=NULL;
        rear=NULL;
    }

    void enqueue(char);
    void dequeue();
    void display();
};

//To add element to queue
void Queue::enqueue(char value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    return;
}

//To remove element from queue
void Queue::dequeue() {
    if (rear == NULL){return;}

    struct node* temp = rear;
    rear = rear->prev;
    if (rear == NULL) {  
        front = NULL;
    } else {
        rear->next = NULL;  
    }
    free(temp);
}

//To display queue
void Queue::display() {
    struct node* temp = front;
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}