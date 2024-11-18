#include <iostream>
#include "QueueArray.h"
#include "QueueLinked.h"
#include "StackArray.h"
#include "StackLinkedList.h"

using namespace std;

void displayMenu() {
    cout << "===============================\n";
    cout << "|     STACK AND QUEUE MENU     |\n";
    cout << "===============================\n";
    cout << "|  1 | Stack Using Array       |\n";
    cout << "|  2 | Queue Using Array       |\n";
    cout << "|  3 | Stack Using Linked List |\n";
    cout << "|  4 | Queue Using Linked List |\n";
    cout << "|  5 | Exit                    |\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    int size;

    cout << "===============================\n";
    cout << "|   ENTER SIZE                |\n";
    cout << "===============================\n";
    cout << "Size: ";
    cin >> size;

    StackArray<int> stack(size);
    QueueArray<int> queue(size);

    StackLinkedList<int> stackLink;
    QueueLinkedList<int> queueLink;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            stack.stackArrayMenu();
            break;
        case 2:
            queue.queueArrayMenu();
            break;
        case 3:
            stackLink.stackLinkedListMenue();
            break;
        case 4:
            queueLink.QueueLinkedListMenu();
            break;
        case 5:
            cout << "===============================\n";
            cout << "|       EXITING PROGRAM        |\n";
            cout << "===============================\n";
            break;
        default:
            cout << "===============================\n";
            cout << "|     INVALID OPTION. TRY AGAIN|\n";
            cout << "===============================\n";
        }
    } while (choice != 5);

    return 0;
}