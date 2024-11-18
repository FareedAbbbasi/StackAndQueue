#include <iostream>
using namespace std;

class StackLinkedListException {
    private:
    string message;

public:
    StackLinkedListException(string e) : message(e) {}
    string getMessage() { return message; }
};

template <class T>
class StackLinkedList {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T &val, Node *n = nullptr) : data(val), next(n) {}
    };
    Node *top;

public:
    // StackLinkedList constructor: create an empty stack
    StackLinkedList() : top(nullptr) {}

    // Check if the stack is empty
    const bool empty() const { return top == nullptr; }

    // Push an element onto the stack
    void push(const T &val);

    // Pop an element from the stack
    T pop();
    void stackLinkedListMenue();
};

// Push operation
template <class T>
void StackLinkedList<T>::push(const T &val) {
    Node *n = new Node(val);
    n->next = top;
    top = n;
}

// Pop operation
template <class T>
T StackLinkedList<T>::pop() {
    if (top == nullptr) {
        throw StackException(
            "\n===============================================\n"
            "|                ⚠️ Error: Underflow           |\n"
            "===============================================\n"
            "| Stack is empty. Cannot pop any elements.     |\n"
            "===============================================\n");
    }
    T val = top->data;
    Node *n = top;
    top = top->next;
    delete n;
    return val;
}

// Template function for menu
template <class T> void StackLinkedList<T>::stackLinkedListMenue(){
    int choice;
    do {
        cout << "\n==========================================\n";
        cout << "|                 Stack Menu             |\n";
        cout << "==========================================\n";
        cout << "| 1. Push element onto the stack         |\n";
        cout << "| 2. Pop element from the stack          |\n";
        cout << "| 3. Exit                                |\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                cout << "\n-----------------------------------------------\n";
                cout << "|                ➕ Push Element               |\n";
                cout << "-----------------------------------------------\n";
                cout << "Enter value to push: ";
                T value;
                cin >> value;
                push(value);
                cout << "✅ Successfully pushed " << value << " onto the stack.\n";
                cout << "-----------------------------------------------\n";
                break;
            }
            case 2: {
                cout << "\n-----------------------------------------------\n";
                cout << "|                ➖ Pop Element                |\n";
                cout << "-----------------------------------------------\n";
                cout << "✅ Successfully popped " << pop() << " from the stack.\n";
                cout << "-----------------------------------------------\n";
                break;
            }
            case 3:
                cout << "\n-----------------------------------------------\n";
                cout << "|               🚪 Exit Selected               |\n";
                cout << "-----------------------------------------------\n";
                break;
            default:
                cout << "\n-----------------------------------------------\n";
                cout << "|              ❌ Invalid Choice              |\n";
                cout << "-----------------------------------------------\n";
                cout << "| Please enter a valid option (1-3).          |\n";
                cout << "-----------------------------------------------\n";
            }
        } catch (StackException &e) {
            cout << e.getMessage();
        }
    } while (choice != 3);
}

// Main function
// int main() {
//     StackLinkedList<int> stack; // Create a stack of integers
//     stackMenu(stack);           // Call the menu function using the stack object

//     return 0;
// }
