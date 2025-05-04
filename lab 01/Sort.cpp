//Program to implement different sorting algorithms: Bubble sort, Selection Sort and Insertion Sort
#include <stdio.h>
#include <cstdlib>

void DisplayArray(int arr[], int n);
void BubbleSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void SelectionSort(int arr[], int n);

int main(){
    int stop=0;
    while (stop==0){
        int choice;
        printf("\nMenu for sorting\n");
        printf("1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Exit\nEnter your choice:");
        scanf("%d", &choice);
        
        if (choice==1||choice==2||choice==3){
            int size;
            printf("\nEnter size of array:");
            scanf("%d", &size);
            int arr[size];
            printf("\nEnter %d elements for the array:\n", size);
            int i=0;
            int e;
            while (i<size){
                scanf("%d", &e);
                if (e>=0){
                    arr[i]=e;
                    i++;
                }
                else{
                    printf("Negative number not allowed. Try again\n");
                }
            }
            printf("The array: ");
            DisplayArray(arr, size);
        
            switch (choice){
            case 1:
                printf("Bubble Sort\n");
                BubbleSort(arr, size);
                printf("\nSorted array:");
                DisplayArray(arr, size);
                break;
            case 2:
                printf("Selection Sort\n");
                SelectionSort(arr, size);
                printf("\nSorted array:");
                DisplayArray(arr, size);
                break;
            case 3:
                printf("Insertion Sort\n");
                InsertionSort(arr, size);
                printf("\nSorted array:");
                DisplayArray(arr, size);
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        }
        else{
            break;
        }    
    }
    return 0;
}

//Function to display all the elements in an array (print the array)
void DisplayArray(int arr[], int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

//Function to sort an array using bubble sort
void BubbleSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j]> arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        DisplayArray(arr, n);
    }
}

//Function to sort an array using insertion sort
void InsertionSort(int arr[], int n){
    for (int i=1; i<n; i++){
        int key= arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        DisplayArray(arr, n);
    }
}

//Function to sort an array using Selection sort
void SelectionSort(int arr[], int n){
    for (int i=0; i<n; i++){
        int minIndex=i;
        for (int j=i+1; j<n; j++){
            if (arr[j]< arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
        DisplayArray(arr, n);
    }
}
