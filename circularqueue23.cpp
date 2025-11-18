#include <iostream>
using namespace std;

#define MAX_SIZE 10  // Queue can hold maximum 10 items

class CircularQueue {
private:
    int arr[MAX_SIZE];  // Array in a CIRCLE (positions 0-9)
    int front;          // Points to first person
    int rear;           // Points to last person
    int count;          // Counts how many people in line

public:
    // Constructor
    CircularQueue() {
        front = 0;   // Ready to start at position 0
        rear = -1;   // No one yet
        count = 0;   // Empty line
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return count == 0;  // If 0 people, it's empty
    }
    
    // Check if queue is full
    bool isFull() {
        return count == MAX_SIZE;  // If 10 people, it's full
    }
    
    // Add element to rear
    void enqueue(int value) {
        // Step 1: Check if full
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        // Step 2: Move rear forward in a CIRCLE using MAGIC FORMULA
        rear = (rear + 1) % MAX_SIZE;
        
        // MAGIC FORMULA EXAMPLES (MAX_SIZE = 10):
        // If rear = -1: (-1+1) % 10 = 0 % 10 = 0 ✓
        // If rear = 5:  (5+1) % 10 = 6 % 10 = 6 ✓ Normal
        // If rear = 9:  (9+1) % 10 = 10 % 10 = 0 ✓ WRAPS to start!
        // If rear = 0:  (0+1) % 10 = 1 % 10 = 1 ✓ Continues
        
        // Step 3: Place person at rear position
        arr[rear] = value;
        
        // Step 4: Increase count
        count++;
        
        cout << value << " enqueued (Queue size: " << count << ")" << endl;
    }
    
    // Remove and return element from front
    int dequeue() {
        // Step 1: Check if empty
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty" << endl;
            return -1;
        }
        
        // Step 2: Remember who's at front
        int value = arr[front];
        
        // Step 3: Move front forward in a CIRCLE
        front = (front + 1) % MAX_SIZE;
        
        // MAGIC FORMULA EXAMPLES:
        // If front = 0: (0+1) % 10 = 1 ✓
        // If front = 9: (9+1) % 10 = 0 ✓ WRAPS to start!
        
        // Step 4: Decrease count
        count--;
        
        return value;
    }
    
    // Look at front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // Show all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear): ";
        
        // Start at front and go in a circle
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % MAX_SIZE;  // Move in circle!
        }
        cout << endl;
        cout << "(front=" << front << ", rear=" << rear << ", count=" << count << ")" << endl;
    }
};

// TESTING THE CIRCULAR QUEUE
int main() {
    cout << "=== CIRCULAR QUEUE DEMO ===" << endl;
    
    CircularQueue q;
    
    // Test 1: Enqueue some values
    cout << "\nTest 1: Enqueue 5 values" << endl;
    q.enqueue(10);  // rear = 0
    q.enqueue(20);  // rear = 1
    q.enqueue(30);  // rear = 2
    q.enqueue(40);  // rear = 3
    q.enqueue(50);  // rear = 4
    q.display();
    
    // Test 2: Dequeue some values
    cout << "\nTest 2: Dequeue 3 values" << endl;
    cout << "Dequeued: " << q.dequeue() << endl;  // front moves 0→1
    cout << "Dequeued: " << q.dequeue() << endl;  // front moves 1→2
    cout << "Dequeued: " << q.dequeue() << endl;  // front moves 2→3
    q.display();
    
    // Test 3: Enqueue more - watch it WRAP AROUND!
    cout << "\nTest 3: Enqueue more values" << endl;
    q.enqueue(60);  // rear = 5
    q.enqueue(70);  // rear = 6
    q.enqueue(80);  // rear = 7
    q.enqueue(90);  // rear = 8
    q.enqueue(100); // rear = 9 (end of array!)
    q.display();
    
    // Test 4: THE MAGIC MOMENT - Wrap around!
    cout << "\nTest 4: Enqueue one more - WRAPS AROUND!" << endl;
    q.enqueue(110); // rear wraps: (9+1) % 10 = 0 ✓ Uses position 0!
    q.display();
    
    cout << "\nNotice: rear = 0 now! It wrapped around!" << endl;
    cout << "Position 0 is REUSED! No space wasted!" << endl;
    
    // Test 5: Fill completely
    cout << "\nTest 5: Fill completely" << endl;
    q.enqueue(120); // rear = 1
    q.enqueue(130); // rear = 2
    q.display();
    
    // Test 6: Try to overflow
    cout << "\nTest 6: Try to enqueue when full" << endl;
    q.enqueue(140); // Should show overflow!
    
    // Test 7: Dequeue all and see positions
    cout << "\nTest 7: Dequeue all" << endl;
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << " ";
    }
    cout << endl;
    q.display();
    
    return 0;
}

/* 
VISUAL REPRESENTATION OF CIRCULAR QUEUE:

Imagine positions arranged in a CIRCLE:

       0  1  2
     9        3
     8        4
       7  6  5

INITIAL STATE:
front = 0, rear = -1, count = 0
All positions empty

AFTER enqueue(10), enqueue(20), enqueue(30):
[10][20][30][  ][  ][  ][  ][  ][  ][  ]
  ↑       ↑
front   rear
count = 3

AFTER dequeue(), dequeue() - removes 10, 20:
[10][20][30][  ][  ][  ][  ][  ][  ][  ]
  ↑↑  ↑↑  ↑
USED  front
      count = 1

Notice: Positions 0 and 1 are now FREE to reuse!

AFTER many enqueues, rear reaches position 9:
[10][20][30][40][50][60][70][80][90][100]
      ↑                               ↑
    front                           rear
count = 8

NOW THE MAGIC: enqueue(110)
rear = (9 + 1) % 10 = 0  ← WRAPS AROUND!

[110][20][30][40][50][60][70][80][90][100]
  ↑   ↑                               ↑
rear front                          old rear
count = 9

Position 0 is REUSED! No space wasted!

This is why it's called "CIRCULAR" - it goes in a circle!

THE % OPERATOR:
% gives remainder after division

Examples with MAX_SIZE = 10:
0 % 10 = 0
5 % 10 = 5
9 % 10 = 9
10 % 10 = 0  ← When you reach 10, wraps to 0!
11 % 10 = 1
15 % 10 = 5
19 % 10 = 9
20 % 10 = 0  ← Wraps again!

This is the SECRET to circular queues!
*/