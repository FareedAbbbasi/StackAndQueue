#include <iostream>
using namespace std;

// Custom exception class for queue errors
class QueueLinkedListException
{
private:
    string msg;

public:
   QueueLinkedListException(string str) : msg(str) {}
    string getMessage() const { return msg; }
};

template <class T>
class QueueLinkedList
{
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value, Node *n = nullptr) : data(value), next(n) {}
    };
    Node *head;

public:
    // Queue constructor: create an empty queue.
    QueueLinkedList() : head(nullptr) {}

    // Check if the queue is empty.
    const bool empty() const { return head == nullptr; }

    // Insert an element at the back of the queue.
    void insert(const T &val);

    // Extract an element from the front of the queue.
    T extract();

    void QueueLinkedListMenu();
};

template <class T>
void QueueLinkedList<T>::insert(const T &val)
{
    Node *n = new Node(val);
    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = n;
    }
}

template <class T>
T QueueLinkedList<T>::extract()
{
    if (head == nullptr)
    {
        throw QueueException("Underflow: Cannot extract element, queue is empty.");
    }

    T val = head->data;
    Node *n = head;
    head = head->next;
    delete n;
    return val;
}

// Template function to handle menu actions and switch statement
template <class T> void QueueLinkedList<T>::QueueLinkedListMenu(){
    int choice;
    do
    {
        cout << "==========================================\n";
        cout << "|                 Menu                   |\n";
        cout << "==========================================\n";
        cout << "| 1. Insert element into the queue       |\n";
        cout << "| 2. Extract element from the queue      |\n";
        cout << "| 3. Exit                                |\n";
        cout << "==========================================\n";
        cout << "| Enter your choice:                     |\n";
        cout << "==========================================\n";
        cout << ">> ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                cout << "-----------------------------------------------\n";
                cout << "|               ➕ Insert Value               |\n";
                cout << "-----------------------------------------------\n";
                T value;
                cout << ">> ";
                cin >> value;
                insert(value);
                cout << "| ✅ Successfully inserted " << value << " into the queue. |\n";
                cout << "-----------------------------------------------\n";
                break;
            }
            case 2:
            {
                cout << "-----------------------------------------------\n";
                cout << "|              ➖ Extract Value               |\n";
                cout << "-----------------------------------------------\n";
                try
                {
                    T extractedValue = extract();
                    cout << "| ✅ Successfully extracted " << extractedValue << " from the queue. |\n";
                }
                catch (QueueException &e)
                {
                    cout << e.getMessage() << "\n";
                }
                cout << "-----------------------------------------------\n";
                break;
            }
            case 3:
                cout << "-----------------------------------------------\n";
                cout << "|           🚪 Exiting the Program            |\n";
                cout << "-----------------------------------------------\n";
                break;
            default:
                cout << "-----------------------------------------------\n";
                cout << "|              ❌ Invalid Choice              |\n";
                cout << "-----------------------------------------------\n";
                cout << "| Please enter a valid option (1-3).          |\n";
                cout << "-----------------------------------------------\n";
            }
        }
        catch (QueueException &e)
        {
            cout << e.getMessage() << endl;
        }
    } while (choice != 3);
}

// int main()
// {
//     QueueLinkedList<int> queue;  // Create a queue of integers

//     cout << "--------------------------------------------------\n";
//     cout << "|          WELCOME TO THE LINKED-LIST QUEUE      |\n";
//     cout << "--------------------------------------------------\n";

//     queueMenu(queue);  // Call the templated menu function for the specific queue type.

//     return 0;
// }
