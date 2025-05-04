//Program to implement Round robin scheduling using circular linked list

#include <iostream>
#include "cll_roundrobin.h"
using namespace std;

int main() {
    int timeslot;
    cout << "Enter fixed time slot: ";
    cin >> timeslot;

    RoundRobinScheduler scheduler(timeslot);
    int choice, time;

    while (true) {
        cout << "\n1. Insert Process\n2. Execute\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
