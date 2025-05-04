//Program to implement queue using array of size 5
#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
    private:
    int arr[SIZE];
    int front, rear;

    public:
    Queue(){
        front=-1;
        rear=-1;
    }

    void Enqueue(int);
    int Dequeue();
    void Peek();
};

int main(){
    Queue q;
    int choice, value;
    while (true){
        cout<<"\nMenu\n"
            <<"1. Enqueue\n"
            <<"2. Dequeue\n"
            <<"3. Peek\n"
            <<"4. Exit\n"
            <<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnqueue"<<endl;
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.Enqueue(value);
                break;
            case 2:
                cout<<"\nDequeue"<<endl;
                value=q.Dequeue();
                if (value!=-1){
                    cout<< value << " successfully dequeued."<<endl;
                }
                break;
            case 3:
                cout<<"\nPeek"<<endl;
                q.Peek();
                break;
            case 4:
                return 0;
            default:
                cout<<"\nInvalid choice. Please try again."<<endl;
                break;
        }
    }
}

//Function to enqueue an element
void Queue::Enqueue(int val){
    if (rear==SIZE-1){
        cout<<"Queue Overflow. Cannot enqueue."<<endl;
        return;
    }
    if (front==-1){
        front = 0;
    }
    arr[++rear]=val;
    cout<< val << " successfully enqueued."<<endl;
    return;
}

//Function to dequeue an element
int Queue::Dequeue(){
    if (front==-1 || front>rear){
        cout<<"Queue Underflow. Cannot dequeue."<<endl;
        return -1;
    }
    int val=arr[front++];
    if (front>rear){
        front = rear = -1;
    }
    return val;
}

//Function to display the front element in the queue
void Queue::Peek(){
    if (front==-1 || front>rear){
        cout<<"Queue Underflow. Nothing to display."<<endl;
        return;
    }
    cout<< "The front element is " << arr[front] << endl;
    return;
}