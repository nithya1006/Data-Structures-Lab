//Program to implement circular linked list

#include <iostream>
#include <cstdlib>
using namespace std;

class listADT{
    private:
    struct node{
        int data;
        struct node* next;
    }*head;

    public:
    listADT() {head=NULL;};

    void InsertBeginning(int);
    void InsertEnd(int);
    void InsertPosition(int, int);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int);
    int Search(int);
    void Display();
};

int main(){
    listADT list;
    int choice, value, pos;
    while (true){
        cout<<"\nMenu\n"
            <<"1. Insert Beginning\n"
            <<"2. Insert End\n"
            <<"3. Insert Position\n"
            <<"4. Delete Beginning\n"
            <<"5. Delete End\n"
            <<"6. Delete Position\n"
            <<"7. Search\n"
            <<"8. Display\n"
            <<"9. Exit\n"
            <<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nInsert Beginning\n";
                cout<<"Enter value to insert: ";
                cin>>value;
                list.InsertBeginning(value);
                break;
            case 2:
                cout<<"\nInsert End\n";
                cout<<"Enter value to insert: ";
                cin>>value;
                list.InsertEnd(value);
                break;
            case 3:
                cout<<"\nInsert Position\n";
                cout<<"Enter position: ";
                cin>>pos;
                cout<<"Enter value to enter at position: ";
                cin>>value;
                list.InsertPosition(pos, value);
                break;
            case 4:
                cout<<"\nDelete Beginning\n";
                value= list.DeleteBeginning();
                if (value!= -1){
                    cout<< "The deleted value: " << value << endl;
                }
                break;
            case 5:
                cout<<"\nDelete End\n";
                value = list.DeleteEnd();
                if (value!=-1){
                    cout<< "The deleted value: " << value << endl;
                }
                break;
            case 6:
                cout<<"\nDelete Position\n";
                cout<<"Enter position: ";
                cin>>pos;
                value=list.DeletePosition(pos);
                if (value!=-1){
                    cout<< "The deleted value: " << value << endl;
                }
                break;
            case 7:
                cout<<"\nSearch\n";
                cout<<"Enter value to search: ";
                cin>>value;
                pos=list.Search(value);
                if (pos!=-1){
                    cout<< "The value is found at position " << pos << " in the list" << endl;
                }
                else{
                    cout<< "The value is not found in the list" << endl;
                }
                break;
            case 8:
                cout<<"\nDisplay\n";
                list.Display();
                break;
            case 9:
                return 0;
            default:
                cout<<"\nInvalid choice. Try again!\n";
                break;
        }
    }
}

//Function to insert given value at the beginning of the circular linked list
void listADT::InsertBeginning(int num){
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
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}


// Function to insert a value at the end of the circular linked list
void listADT::InsertEnd(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;   
    if (!head) {
        newnode->next = newnode;
        head = newnode;
        return;
    }   
    struct node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

//Function to delete the first element of the circular linked list
int listADT::DeleteBeginning(){
    if (!head) {
        cout<<"List is empty"<<endl;
        return -1;
    }
    int value = head->data;
    struct node* temp = head;
    if (head->next == head) { 
        head = NULL;
    } 
    else {
        struct node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
    }
    free(temp);
    return value;
}


//Function to delete the last element of the circular linked list
int listADT::DeleteEnd(){
    if (!head) {
        cout<<"List is empty"<<endl;
        return -1;
    }
    struct node *temp = head, *prev = NULL;
    while (temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    int value = temp->data;
    if (!prev) {
        head = NULL;
    } else {
        prev->next = head;
    }
    free(temp);
    return value;
}

//Function to print all the elements in the circular linked list
void listADT::Display(){
    if (head==NULL){
        cout<<"List is empty\n";
        return;
    }
    struct node* temp=head;
    do {
        cout<< temp->data << " ";
        temp= temp->next;
    } while (temp!=head);
    cout<<endl;
}

// Function to insert at a given value at a specified position
void listADT::InsertPosition(int pos, int num){
    if (!head || pos == 1) {
        InsertBeginning(num);
        return;
    } 
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    struct node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}


// Function to delete a node at a specified position
int listADT::DeletePosition(int pos){
    if (!head){
        cout<<"List is empty"<<endl;
        return -1;
    }
    if (pos == 1) return DeleteBeginning();
    
    struct node* temp = head, *prev = NULL;
    int count = 1;
    do {
        if (count == pos) break;
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head);
    
    if (count != pos) {
        cout<<"Position out of bounds"<<endl;
        return -1;
    }
    prev->next = temp->next;
    int value = temp->data;
    free(temp);
    return value;
}

// Function to search for a value in the circular linked list
int listADT::Search(int num){
    if (!head) return -1;
    struct node* temp = head;
    int pos = 1;
    do {
        if (temp->data == num) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}