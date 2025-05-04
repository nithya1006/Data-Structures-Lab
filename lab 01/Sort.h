//Program to implement header file for sorting algorithms
#include <stdio.h>
#include <cstdlib>

void BubbleSort(int arr[], int n, int idx[]){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j]> arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                int temp1=idx[j];
                idx[j]=idx[j+1];
                idx[j+1]=temp1;
            }
        }
    }
}

void InsertionSort(int arr[], int n, int idx[]){
    for (int i=1; i<n; i++){
        int key= arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            idx[j+1]=idx[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void SelectionSort(int arr[], int n, int idx[]){
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

        int temp1=idx[i];
        idx[i]=idx[minIndex];
        idx[minIndex]=temp;
    }
}

void DisplayArray(int arr[], int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}