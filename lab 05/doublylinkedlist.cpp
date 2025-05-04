//Menu driven program of ListADT - Doubly linked list implementation

#include <iostream>
#include <cstdlib>
using namespace std;

class listADT{
    private:
    struct node{
        int data;
        struct node* prev;
        struct node* next;
    }*head, *tail;

    public:
    listADT() {head=NULL, tail=NULL;};
    
    void InsertBeginning(int);
    void InsertEnd(int);
    void InsertPosition(int, int);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int);
    int Search(int);
    void Display();
    void DisplayReverse();
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
            <<"9. Display Reverse\n"
            <<"10. Exit\n"
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
                cout<<"\nDisplay Reverse\n";
                list.DisplayReverse();
                break;
            case 10:
                return 0;
            default:
                cout<<"\nInvalid choice. Try again!\n";
                break;
        }
    }
}

//Function to insert given value at the beginning of the doubly linked list
void listADT::InsertBeginning(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    newnode->prev=NULL;
    if (!head){
        head = newnode;
        tail = newnode;
    }
    else{
        head->prev=newnode;
        head=newnode;
    }
    return;
}

//Function to print all the elements in the doubly linked list
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

//Function to insert a given value at the end of the doubly linked list
void listADT::InsertEnd(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    newnode->prev=tail;
    if (!head){
        head=newnode;
        tail=newnode;
    }
    else {
        tail->next=newnode;
        tail=newnode;
    }
    return;
}

//Function to insert a given value at a given position in the doubly linked list
void listADT::InsertPosition(int pos, int num){
    if (pos<=0){
        cout<<"Invalid position\n";
        return;
    }
    else if (pos==1){
        InsertBeginning(num);
        return;
    }
    else{
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        struct node* temp=head;
        for (int i=1; temp && i<pos-1; i++){
            temp=temp->next;
        }

        if (!temp){
            cout<< "Position out of bounds\n";
            return;
        }
        temp->next->prev=newnode;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
}

//Function to delete the starting element in the doubly linked list and return the deleted value
int listADT::DeleteBeginning(){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    struct node* temp = head;
    int data= temp->data;
    if (!temp->next){
        free(head);
        head=NULL;
        return data;
    }
    temp->next->prev=NULL;
    head=head->next;
    free(temp);
    return data;
}

//Function to delete the last element in the doubly linked list and return the deleted value
int listADT::DeleteEnd(){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    int data=tail->data;
    if (!head->next){
        free(head);
        head=NULL;
        return data;
    }
    tail->prev->next=NULL;
    tail=tail->prev;
    return data;
}

//Function to delete an element from the given position in the doubly linked list and return the deleted value
int listADT::DeletePosition(int pos){
    if (head==NULL){
        cout<<"List is empty\n";
        return -1;
    }
    if (pos<=0){
        cout<<"Invalid position\n";
        return -1;
    }
    else if (pos==1){
        return DeleteBeginning();
    }
    else{
        struct node* temp =head;
        for (int i=1; temp->next && i<pos-1; i++){
            temp=temp->next;
        }
        if (!temp->next){
            cout<<"Position out of bounds\n";
            return -1;
        }
        struct node* delnode=temp->next;
        if (delnode==tail){
            return DeleteEnd();
        }
        int data=delnode->data;
        temp->next=delnode->next;
        delnode->next->prev=temp;
        free(delnode);
        return data;
    }
}

//Function to find the position of a given value in the doubly linked list if it is present 
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
//Function to display all the elements in the list in reverse
void listADT::DisplayReverse(){
    if (head==NULL){
        cout<<"List is empty\n";
        return;
    }
    struct node* temp=tail;
    while (temp){
        cout<< temp->data << " ";
        temp= temp->prev;
    }
    cout<<endl;
}