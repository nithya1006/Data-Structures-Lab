//Program to implement Stack ADT using character array of size 5

#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 5

class StackADT{
    private:
    char arr[SIZE];
    int size;

    public:
    StackADT() {size=0;};

    void Push(char);
    char Pop();
    void Peek();
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
                if (character!='0'){
                    cout<<"The popped element is " << character << endl;
                }
                break;
            case 3:
                cout<<"\nPeek\n";
                stack.Peek();
                break;
            case 4:
                return 0;
            default:
                cout<<"\nInvalid choice. Try again!\n";
                break;
        }
    }
}

//Function to push a given character to the stack array
void StackADT::Push(char chr){
    if (size>=SIZE){
        cout<<"Stack Overflow. Cannot push character\n";
        return;   
    }
    arr[size++]=chr;
}

//Function to pop the top character in the stack array and return it
char StackADT::Pop(){
    if (size==0){
        cout<<"Stack Underflow. Cannot pop character\n";
        return '0';
    }
    char chr = arr[size-1];
    size--;
    return chr;
}

//Function to display the top element in the stack array
void StackADT::Peek(){
    if (size==0){
        cout<<"Stack is Empty\n";
        return;
    }
    cout<< "The value at the top is " << arr[size-1]<<endl;
}