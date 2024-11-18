#include <iostream>
using namespace std;

// StackException class for handling errors
class StackException
{
private:
    string msg;

public:
    StackException(string str) : msg(str) {}
    string getMessage()
    {
        return msg;
    }
};

// Template class for StackArray
template <class T>
class StackArray
{
private:
    T *stack;
    int top, size;

public:
    // StackArray constructor: create an empty stack with a given size
    StackArray(int n = 0) : stack(new T[n]), top(-1), size(n) {}

    // StackArray Destructor: delete the stack
    ~StackArray() { delete[] stack; }

    // Check if the stack is empty
    const bool empty() const { return top == -1; }

    // Push an element onto the stack
    void push(const T &val);

    // Pop an element from the stack
    T pop();

    void stackArrayMenu();
};

// StackArray push operation
template <class T>
void StackArray<T>::push(const T &val)
{
    if (top == size - 1)
    {
        throw StackException(
            "\n===============================================\n"
            "|                 ⚠️ Error: Overflow           |\n"
            "===============================================\n"
            "| Stack is full. Cannot push any more elements |\n"
            "===============================================\n");
    }
    top = top + 1;
    stack[top] = val;
}

// StackArray pop operation
template <class T>
T StackArray<T>::pop()
{
    if (top == -1)
    {
        throw StackException(
            "\n===============================================\n"
            "|                ⚠️ Error: Underflow           |\n"
            "===============================================\n"
            "| Stack is empty. Cannot pop any elements.     |\n"
            "===============================================\n");
    }

    T val = stack[top];
    top = top - 1;
    return val;
}

// Template function to handle stack menu
template <class T> void StackArray<T>::stackArrayMenu(){
    int choice;
    do
    {
        cout << "\n==========================================\n";
        cout << "|                 Stack Menu             |\n";
        cout << "==========================================\n";
        cout << "| 1. Push element onto the stack         |\n";
        cout << "| 2. Pop element from the stack          |\n";
        cout << "| 3. Exit                                |\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
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

            case 2:
                cout << "\n-----------------------------------------------\n";
                cout << "|                ➖ Pop Element                |\n";
                cout << "-----------------------------------------------\n";
                cout << "✅ Successfully popped " << pop() << " from the stack.\n";
                cout << "-----------------------------------------------\n";
                break;

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
        }
        catch (StackException &e)
        {
            cout << e.getMessage();
        }
    } while (choice != 3);
}

// Main function
// int main()
// {
//     StackArray<int> stack(5); // Create a stack with size 5
//     stackMenu(stack);         // Call the menu template function

//     return 0;
// }
