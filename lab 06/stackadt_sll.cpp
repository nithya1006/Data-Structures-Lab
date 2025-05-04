//Program to implement StackADT using singly linked list

#include <iostream>
#include <cstdlib>
using namespace std;

class StackADT{
    private:
    struct node{
        char data;
        struct node* next;
    }*head, *tail;

    public:
    StackADT() {head=NULL, tail=NULL;};

    void Push(char);
    char Pop();
    char Peek();
};

int main(){
    StackADT stack;
    int choice;
    char character;

    while(true){
        cout<<"\nMenu\n"
            <<"1. Push\n"
            <<"2. Pop\n"
            <<"3. Peek\n"
            <<"4. Exit\n"
            <<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nPush\n";
                cout<<"Enter character to push: ";
                cin>>character;
                stack.Push(character);
                break;
            case 2:
                cout<<"\nPop\n";
                character=stack.Pop();
                if (character!='\0'){
                    cout<<"The popped element is " << character << endl;
                }
                break;
            case 3:
                cout<<"\nPeek\n";
                character=stack.Peek();
                if (character!='\0'){
                    cout<<"The element at the top of the stack is " << character <<endl;
                }
                break;
            case 4:
                return 0;
            default:
                cout<<"\nInvalid choice. Try again!\n";
                break;
        }
    }
}

//Function to push an element to the stack implemented using singly linked list
void StackADT::Push(char chr) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = chr;
    newnode->next = NULL;

    if (head == NULL) { 
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

//Function to pop the top element in the stack implemented using sll and return it
char StackADT::Pop() {
    if (head == NULL) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    
    char data;
    if (head == tail) {
        data = head->data;
        free(head);
        head = tail = NULL;
    } else {
        struct node* temp = head;
        while (temp->next != tail) { 
            temp = temp->next;
        }
        data = tail->data;
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
    return data;
}

//Function to display the top most element in the stack implemented using sll
char StackADT::Peek() {
    if (tail == NULL) {
        cout << "Stack is empty\n";
        return '\0';
    } else {
        return tail->data;
    }
}