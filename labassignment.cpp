#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    string customerName;
    Node* next;

    Node(const string& name) : customerName(name), next(nullptr) {}
};

/**
 * Dynamic (Linked List) Implementation of Customer Service Queue.
 * Allows for dynamic resizing with no predefined capacity limit.
 */
class CustomerServiceQueueLinkedList {
private:
    Node* front; // Head
    Node* rear;  // Tail

public:
    // Constructor
    CustomerServiceQueueLinkedList() : front(nullptr), rear(nullptr) {}

    // Destructor (Frees all dynamically allocated memory)
    ~CustomerServiceQueueLinkedList() {
        while (!isEmpty()) {
            dequeue(); 
        }
    }

    // 4. Checks if the queue is empty.
    bool isEmpty() const {
        return front == nullptr;
    }

    // 1. Adds a new customer to the rear (Enqueue).
    void enqueue(const string& customerName) {
        Node* newNode = new Node(customerName);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << customerName << " has joined the line." << endl;
    }

    // 2. Removes and returns the customer at the front (Dequeue).
    string dequeue() {
        if (isEmpty()) {
            cout << "No customers in line." << endl;
            return "";
        }

        Node* temp = front;
        string servedCustomer = temp->customerName;

        front = front->next; // Move front forward

        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }

        delete temp; // Free the memory of the served node
        
        cout << "Serving and removing: " << servedCustomer << endl;
        return servedCustomer;
    }

    // 3. Returns the customer at the front without removing (Peek).
    string peek() const {
        if (isEmpty()) {
            return "No customers in line.";
        }
        return front->customerName;
    }
};

// Main function for the Dynamic Queue Program
int main() {
    cout << "--- Dynamic Linked List Queue Simulation ---" << endl;
    CustomerServiceQueueLinkedList listQueue;
        
    // 1. Enqueue Test
    listQueue.enqueue("Ali");
    listQueue.enqueue("Bilal");
    listQueue.enqueue("Zara");

    // 2. Peek and Serve
    cout << "\nNext (Peek): " << listQueue.peek() << endl;
    listQueue.dequeue(); // Serves Ali

    // 3. Mixed Operations (Testing Dynamic Growth)
    listQueue.enqueue("Daniyal"); 
    listQueue.dequeue(); // Serves Bilal
    listQueue.enqueue("Fahad"); 
    listQueue.enqueue("Faraz"); 
    listQueue.enqueue("Hassan"); // Added successfully (dynamic)

    // 4. Emptying the Queue
    cout << "\nEmptying the Queue:" << endl;
    while (!listQueue.isEmpty()) {
        listQueue.dequeue();
    }
    
    // 5. Test Empty Dequeue
    listQueue.dequeue(); 

    cout << "\nFinal Check: Is the queue empty? " << (listQueue.isEmpty() ? "True" : "False") << endl;

    return 0;
}