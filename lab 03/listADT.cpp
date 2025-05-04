//Program to implement listADT using array
#include <stdio.h>
class listADT{
    private:
    int arr[5];
    int size;

    public:
    listADT();

    void InsertBeginning(int value);
    void InsertEnd(int value);
    void InsertPosition(int pos, int value);
    int DeleteBeginning();
    int DeleteEnd();
    int DeletePosition(int pos);
    int Search(int value);
    void Display();
    void Rotate(int k);
};

int main()
{
    listADT list;
    int choice, value, pos, k;

    while (true){
        printf("\nMenu\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n");
        printf("4. Delete Beginning\n5. Delete End\n6. Delete Position\n");
        printf("7. Search\n8. Display\n9. Rotate\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nInsert Beginning\n");
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                list.InsertBeginning(value);
                break;
            case 2:
                printf("\nInsert End\n");
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                list.InsertEnd(value);
                break;
            case 3:
                printf("\nInsert Position\n");
                printf("Enter position(1-5): ");
                scanf("%d", &pos);
                printf("Enter value to insert at position: ");
                scanf("%d", &value);
                list.InsertPosition(pos, value);
                break;
            case 4:
                printf("\nDelete Beginning\n");
                value=list.DeleteBeginning();
                if (value!=-1){
                    printf("The deleted value: %d\n", value);
                } 
                break;
            case 5:
                printf("\nDelete End\n");
                value=list.DeleteEnd();
                if (value!=-1){
                    printf("The deleted value: %d\n", value);
                } 
                break;
            case 6:
                printf("\nDelete Position\n");
                printf("Enter position(1-5): ");
                scanf("%d", &pos);
                value=list.DeletePosition(pos);
                if (value!=-1){
                    printf("The deleted value: %d\n", value);
                }
                break;
            case 7:
                printf("\nSearch\n");
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos=list.Search(value);
                if (pos==-1){
                    printf("The element not found\n");
                }
                else{
                    printf("The element is found at position %d\n", pos);
                }
                break;
            case 8:
                printf("\nDisplay\n");
                list.Display();
                break;
            case 9:
                printf("\nRotate\n");
                printf("Enter k (no. of times to rotate): ");
                scanf("%d", &k);
                list.Rotate(k);
                break;
            case 10:
                return 0;
            default:
                printf("\nInvalid choice! Try again!\n");
                break;
        }
    }
}
listADT::listADT(): size(0){}

//Function to insert an given value at the beginning of the array
void listADT::InsertBeginning(int value)
{
    if (size>=5){
        printf("List is full\n");
        return;
    }
    for (int i=size; i>0; --i){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    size++;
}

//Function to display all the elements in the array
void listADT::Display(){
    if (size==0){
        printf("List is empty\n");
        return;
    }

    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Function to insert an given value at the end of the array
void listADT::InsertEnd(int value){
    if (size>=5){
        printf("List is full\n");
        return;
    }
    arr[size++]=value;
}

//Function to insert an given value at a given position in the array
void listADT::InsertPosition(int pos, int value){
    if (size>=5){
        printf("List is full\n");
        return;
    }
    if (pos<1||pos>size+1){
        printf("Invalid position\n");
        return;
    }
    for (int i=size; i>pos-1; --i){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    size++;
}

//Function to delete element from the beginning of the array and return it
int listADT::DeleteBeginning(){
    if (size==0){
        printf("List is empty\n");
        return -1;
    }
    int val=arr[0];
    for(int i=0; i<size-1;++i){
        arr[i]=arr[i+1];
    }
    size--;
    return val;
}

//Function to delete element from the end of the array and return it
int listADT::DeleteEnd(){
    if (size==0){
        printf("List is empty\n");
        return -1;
    }
    int val=arr[size-1];
    size--;
    return val;
}

//Function to delete element from a given position of the array and return it
int listADT::DeletePosition(int pos){
    if (size==0){
        printf("List is empty\n");
        return -1;
    }
    if (pos<1||pos>size){
        printf("Invalid position\n");
        return -1;
    }
    int val=arr[pos-1];
    for (int i=pos-1; i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return val;
}

//Function search a given value in the array and return its position if its present, otherwise returns -1
int listADT::Search(int value){
    for (int i=0; i<size;i++){
        if (arr[i]==value){
            return i+1;
        }
    }
    return -1;
}

//Function to rotate the array k number of times
void listADT::Rotate(int k){
    if (size==0){
        printf("List is empty\n");
        return;
    }
    k=k%size;
    for (int i=0; i<k;i++){
        int temp=arr[size-1];
        for (int j=size-1; j>0; --j){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
    return;
}