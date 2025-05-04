//Program to remove '+' and immediate left non '+' symbol from a string

#include <iostream>
#include <stdio.h>
#include "queue_dll.h"
using namespace std;

//To process the input string
void processInput(char input[]) {  
    Queue q;
    for (int i = 0; input[i] != '\0'; i++) {  
        if (input[i] == '+') {
            q.dequeue();  
        } else {
            q.enqueue(input[i]);  
        }
    }
    q.display();  
}

int main() {
    char input[100]; 
    cout << "Enter a string with '+': ";
    cin >> input;  

    cout << "Processed Output: ";
    processInput(input);  

    return 0;
}
