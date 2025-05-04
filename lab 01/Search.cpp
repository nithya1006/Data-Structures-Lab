//Program to implement linear search and binary search
#include <stdio.h>
#include <cstdlib>
#include "sort.h"

void LinearSearch(int arr[], int n, int target);
void BinarySearch(int arr[], int n, int target, int idx[]);

int main(){
    int stop=0;
    while (stop==0){
        int target, choice, size;
        printf("\nMenu for searching\n");
        printf("1.Linear Search\n2.Binary Search\n3.Exit\nEnter your choice:");
        scanf("%d", &choice);
        if (choice==1||choice==2){
            printf("\nEnter size of array:");
            scanf("%d", &size);
            int arr[size];
            int idx[size];
            printf("\nEnter %d elements for the array:\n", size);
            int i=0;
            while (i<size){
                int e;
                scanf("%d", &e);
                if (e>=0){
                    arr[i]=e;
                    idx[i]=i;
                    i++;
                }
                else{
                    printf("Negative number not allowed. Try again\n");
                }
            }
            DisplayArray(arr, size);
            printf("Enter element to search:");
            scanf("%d", &target);
            switch (choice){
                case 1:
                    LinearSearch(arr, size, target);
                    break;
                case 2:
                    BubbleSort(arr, size, idx);
                    BinarySearch(arr, size, target, idx);
                    break;
                default:
                    printf("Invalid choice!");
                    break;   
            }
        }
        else{
            break;
        }
    }
}

//Function to search for a target element in an array using linear search
void LinearSearch(int arr[], int n, int target){
    int found=0;
    for (int i=0; i<n; i++){
        if (arr[i]==target){
            printf("The target element found at index %d\n", i);
            found=1;
        }
    }
    if (found==0){
        printf("The target element not found\n");
    }
    return;
}

//Function to search for a target element in an array using binary search
void BinarySearch(int arr[], int n, int target, int idx[]){
    int left=0;
    int right=n-1;
    int found=0;
    while (left<=right){
        int mid= (left+right)/2;
        if (arr[mid]==target){
            printf("Target element found at index %d in the array\n",idx[mid]);
            found=1;
            break;
        }
        else if (arr[mid]<target){
            left= mid+1;
        }
        else if (arr[mid]>target){
            right=mid-1;
        }
    }
    if (found==0){
        printf("The target element not found\n");
    }
    return;
}