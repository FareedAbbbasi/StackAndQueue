#include <iostream>
using namespace std;

class QueueException
{
private:
    string msg;

public:
    QueueException(string str) : msg(str) {}
    string getMessage() const { return msg; }
};

template <class T>
class QueueArray
{
private:
    T *queue;
    int front, rear, size;

public:
    // QueueArray constructor: create the empty queue.
    QueueArray(int n = 0) : queue(new T[n + 1]), front(0), rear(0), size(n + 1) {}

    // QueueArray destructor: delete the queue.
    ~QueueArray() { delete[] queue; }

    // Check if the queue is empty.
    const bool empty() const { return front == rear; }

    // Check if the queue is full.
    const bool full() const { return (rear + 1) % size == front; }

    // Insert an element at the back of the queue.
    void insert(const T &val);

    // Remove an element from the front of the queue.
    T extract();
    void queueArrayMenu();
};

template <class T>
void QueueArray<T>::insert(const T &val)
{
    if (full())
    {
        cout << "--------------------------------------------------\n";
        cout << "|                ⚠️ Queue Overflow               |\n";
        cout << "--------------------------------------------------\n";
        cout << "| Error: Overflow - Cannot insert element, queue  |\n";
        cout << "| is full. Please remove some elements to make    |\n";
        cout << "| space.                                          |\n";
        cout << "--------------------------------------------------\n";
        throw QueueException("Overflow: Cannot insert element, queue is full.\n");
    }
    rear = (rear + 1) % size;
    queue[rear] = val;
}

template <class T>
T QueueArray<T>::extract()
{
    if (empty())
    {
        cout << "--------------------------------------------------\n";
        cout << "|                ⚠️ Queue Underflow               |\n";
        cout << "--------------------------------------------------\n";
        cout << "| Error: Underflow - Cannot extract element,     |\n";
        cout << "| queue is empty.                                |\n";
        cout << "| Please insert elements before extraction.      |\n";
        cout << "--------------------------------------------------\n";
        throw QueueException("Underflow: Cannot extract element, queue is empty.\n");
    }

    front = (front + 1) % size;
    return queue[front];
}

// Template function to handle menu actions and switch statement
template <class T> void QueueArray<T>::queueArrayMenu(){
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
        cout << ">>";
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
                    cout << ">>";
                    cin >> value;
                    insert(value);
                    cout << "| ✅ Successfully inserted " << value << " into the queue.     |\n";
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
                        cout << "* ✅ Successfully extracted " << extractedValue << " from the queue.  *\n";
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
//     int queueSize;
//     cout << "--------------------------------------------------\n";
//     cout << "|          INPUT THE SIZE OF THE QUEUE            |\n";
//     cout << "--------------------------------------------------\n";
//     cout << ">>";
//     cin >> queueSize;

//     QueueArray<int> queue(queueSize);

//     queueMenu(queue); // Call the templated menu function for the specific queue type.

//     return 0;
// }
