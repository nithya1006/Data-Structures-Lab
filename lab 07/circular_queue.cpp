//Program to implement Circular Queue using array of size 5
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue{
    private:
    int arr[SIZE];
    int front, rear;

    public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    
    bool isFull();
    bool isEmpty();
    void Enqueue(int);
    int Dequeue();
    void Peek();
};

int main(){
    CircularQueue q;
    int choice, value;
    cout<<"Circular Queue";
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
                cout<<"\nEnqueue\n";
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.Enqueue(value);
                break;
            case 2:
                cout<<"\nDequeue\n";
                value = q.Dequeue();
                if (value!=-1){
                    cout<< value << " successfully dequeued." << endl;
                }
                break;
            case 3:
                cout<<"\nPeek\n";
                q.Peek();
                break;
            case 4:
                return 0;
            default:
                cout<<"\nInvalid choice. Please try again.\n";
                break;
        }
    }
}

//Function to check if the queue is full
bool CircularQueue::isFull(){
    return (rear==SIZE-1 && front==0 || front == rear + 1);
}

//Function to check if the queue is empty
bool CircularQueue::isEmpty(){
    return (front==-1);
}

//Function to enqueue an element
void CircularQueue::Enqueue(int val){
    if (isFull()){
        cout<<"Queue Overflow. Cannot enqueue."<<endl;
        return;
    }

    if (isEmpty()){
        front = rear = 0;
    }
    else{
        rear= (rear+1)%SIZE;
    }
    arr[rear]=val;
    cout<< val << " successfully enqueued." <<endl;
    return;
}

//Function to dequeue an element
int CircularQueue::Dequeue(){
    if (isEmpty()){
        cout<<"Queue Underflow. Cannot dequeue."<<endl;
        return -1;
    }
    int val = arr[front];
    if (front==rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%SIZE;
    }
    return val;
}

//Function to display the front element in the queue
void CircularQueue::Peek(){
    if (isEmpty()){
        cout<<"Queue Underflow. Nothing to display."<<endl;
        return;
    }
    cout<< "The front element is " << arr[front] << endl;
    return; 
}