//Program to implement listADT using singlylinkedlist
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
    void DisplayReverse();
    void DisplayReverseHelper(struct node*);
    void ReverseLink();
};

int main(){
    listADT list;
    int choice, value, pos, size;
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
            <<"9. Display Reverse\n"
            <<"10. Reverse Link\n"
            <<"11. Exit\n"
            <<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nInsert Beginning\n";
                cout<<"Enter value to insert: ";
                cin>>value;
                list.InsertBeginning(value);
                size++;
                break;
            case 2:
                cout<<"\nInsert End\n";
                cout<<"Enter value to insert: ";
                cin>>value;
                list.InsertEnd(value);
                size++;
                break;
            case 3:
                cout<<"\nInsert Position\n";
                cout<<"Enter position: ";
                cin>>pos;
                cout<<"Enter value to enter at position: ";
                cin>>value;
                list.InsertPosition(pos, value);
                size++;
                break;
            case 4:
                cout<<"\nDelete Beginning\n";
                value= list.DeleteBeginning();
                if (value!= -1){
                    cout<< "The deleted value: " << value << endl;
                }
                size--;
                break;
            case 5:
                cout<<"\nDelete End\n";
                value = list.DeleteEnd();
                if (value!=-1){
                    cout<< "The deleted value: " << value << endl;
                }
                size--;
                break;
            case 6:
                cout<<"\nDelete Position\n";
                cout<<"Enter position: ";
                cin>>pos;
                value=list.DeletePosition(pos);
                if (value!=-1){
                    cout<< "The deleted value: " << value << endl;
                }
                size--;
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
                cout<<"\nDisplay Reverse\n";
                list.DisplayReverse();
                break;
            case 10:
                cout<<"\nReverse Link\n";
                list.ReverseLink();
                break;
            case 11:
                return 0;
            default:
                cout<<"\nInvalid choice. Try again!\n";
                break;
        }
    }
}

//Function to insert given value at the beginning of the singly linked list
void listADT::InsertBeginning(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (!newnode){
        cout<<"Memory allocation failed";
        return;
    }
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return;
}

//Function to print all the elements in the singly linked list
void listADT::Display(){
    if (head==NULL){
        cout<<"List is empty\n";
        return;
    }
    struct node* temp=head;
    while (temp){
        cout<< temp->data << " ";
        temp= temp->next;
    }
    cout<<endl;
}

//Function to insert a given value at the end of the singly linked list
void listADT::InsertEnd(int num){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    if (!newnode){
        cout<<"Memory allocation failed\n";
        return;
    }
    newnode->data=num;
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;    
        while (temp->next){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return;
}

//Function to insert a given value at a given position in the singly linked list
void listADT::InsertPosition(int pos, int num){
    if (pos<=0){
        cout<<"Invalid position\n";
        return;
    }
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    if (pos==1){
        InsertBeginning(num);
        return;
    }
    else{
        struct node* temp=head;
        for (int i=1; temp && i<pos-1; i++){
            temp=temp->next;
        }

        if (!temp){
            cout<< "Position out of bounds\n";
            return;
        }
        newnode->data=num;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return;
}

//Function to delete the starting element in the singly linked list and return the deleted value
int listADT::DeleteBeginning(){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    struct node* temp=head;
    int data= temp->data;
    head=head->next;
    free(temp);
    return data;
}

//Function to delete the last element in the singly linked list and return the deleted value
int listADT::DeleteEnd(){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    int data;
    if (head->next==NULL){
        data = head->data;
        free(head);
        head=NULL;
        return data;
    }
    struct node* temp=head;
    while (temp->next->next){
        temp=temp->next;
    }
    data=temp->next->data;
    free(temp->next);
    temp->next= NULL;
    return data;
}

//Function to delete an element from the given position in the singly linked list and return the deleted value
int listADT::DeletePosition(int pos){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    if (pos<=0){
        cout<<"Invalid position";
        return -1;
    }
    if (pos==1){
        return DeleteBeginning();
    }
    else{
        struct node* temp=head;
        for (int i=1; temp->next && i<pos-1; i++){
            temp=temp->next;
        }
        if (!temp->next){
            cout<<"Position out of bounds\n";
            return -1;
        }
        struct node* delnode = temp->next;
        int data= delnode->data;
        temp->next=delnode->next;
        free(delnode);
        return data;
    }
}

//Function to find the position of a given value in the singly linked list if it is present
int listADT::Search(int num){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    int pos=1;
    struct node* temp=head;
    while (temp){
        if (temp->data == num){
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    return -1;
}
//Function to help the function DisplayReverse
void listADT::DisplayReverseHelper(struct node* head) {
    if (!head) return;
    DisplayReverseHelper(head->next);
    cout << head->data << " ";
}

// Function to display list in reverse order
void listADT::DisplayReverse(){ 
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    DisplayReverseHelper(head);
    cout << endl;
}

// Function to reverse the linked list
void listADT::ReverseLink() {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}