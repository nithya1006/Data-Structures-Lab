//Program to perform operations between two sll
#include <iostream>
#include "listADT_B.h"
using namespace std;

int main() {
    ListADT list1, list2, list3;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n"
              << "1. Insert List1\n"
              << "2. Insert List2\n"
              << "3. Merge into List3\n"
              << "4. Display\n"
              << "5. Exit\n"
              << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert in List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value to insert in List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3.merge(list1, list2);
                cout << "Lists merged into List3.\n";
                break;
            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    }
}