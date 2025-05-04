//Header file of roundrobin using circularlinkedlist
#ifndef CLL_ROUNDROBIN_H
#define CLL_ROUNDROBIN_H

#include <iostream>
#include <cstdlib>
using namespace std;

class listADT {
private:
    struct node {
        int data;
        struct node* next;
    } *head;

public:
    listADT() { head = NULL; }

    void InsertEnd(int);
    int DeleteBeginning();
    void Display();
    bool isEmpty();
};

// Function to insert a value at the end of the circular linked list
void listADT::InsertEnd(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (!head) {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

// Function to delete the first element in the circular linked list
int listADT::DeleteBeginning() {
    if (!head) return -1;
    int value = head->data;
    struct node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
    }
    free(temp);
    return value;
}

// Function to print elements of the circular linked list
void listADT::Display() {
    if (head == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    struct node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

//Function to check if the circular linked list is empty
bool listADT::isEmpty(){
    return head == NULL; 
};

class RoundRobinScheduler {
private:
    listADT queue;
    int timeslot;

public:
    RoundRobinScheduler(int tq) : timeslot(tq) {}

    void insertProcess(int);
    void execute();
};

//Function to insert a process with a given time at the end of the circular linked list
void RoundRobinScheduler::insertProcess(int time) {
    queue.InsertEnd(time);
    cout << "Process with time " << time << " inserted.\n";
}

//Function to execute a process in the circular linked list
void RoundRobinScheduler::execute() {
    if (queue.isEmpty()) {
        cout << "No processes to execute.\n";
        return;
    }

    int time = queue.DeleteBeginning();
    int remainingTime = time - timeslot;
    cout << "Executing process with time " << time << "...";

    if (remainingTime <= 0) {
        cout << " Process completed.\n";
    } else {
        cout << " Remaining time: " << remainingTime << "\n";
        queue.InsertEnd(remainingTime);
    }
}

#endif