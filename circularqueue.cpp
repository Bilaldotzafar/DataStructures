#include <iostream>
using namespace std;


class queue {

private:

int arr[100];
int front;
int rear;
int count;
public:

queue(){

    front = 0;
    rear = -1;
    count = 0;
}


void enqueue(int value){
if (count >= 100){
    cout << "queue is full";
    return;
}
rear = (rear + 1) % 100;
arr[rear] = value;
count++;
}

int dequeue(){
    if(count == 0){
        cout << "queue is empty";
        return -1;
    }
    int value = arr[front];
    front = (front + 1 ) % 100;
    count--;
    return value;
}
bool isEmpty(){
    return count == 0;
}
int sizze(){
    return count;
}
int peek(){

    if(count == 0){
        cout << "queue is empty";
        return -1;

    }
    return arr[front];

}
void display(){
    if(count == 0){
        cout << " queue is empty";
        return;
    }
    cout << "queue elements:  ";
    for(int i = 0; i < count; i++){

        int index = (front +i) % 100;
        cout << arr[index];

    }
    cout <<"\n";
}


};

int main(){

    queue q;

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(324);



    q.display();




    q.dequeue();
    q.dequeue();
}


FUNCTION Delete_Internal_Element(Queue, MaxSize, FRONT, REAR, TargetValue):

    // 1. Locate the Target Element and its index (FoundIndex)
    CurrentIndex = FRONT
    FoundIndex = -1
    
    // Traverse the queue circularly from FRONT to REAR
    DO:
        IF Queue[CurrentIndex] == TargetValue:
            FoundIndex = CurrentIndex
            BREAK
        CurrentIndex = (CurrentIndex + 1) MOD MaxSize
    WHILE CurrentIndex != (REAR + 1) MOD MaxSize

    IF FoundIndex == -1:
        RETURN "Error: Target value not found."
        
    // 2. Shift all subsequent elements one position forward
    ShiftIndex = FoundIndex
    
    // Continue shifting until the element *at* REAR has been moved
    WHILE ShiftIndex != REAR:
        NextIndex = (ShiftIndex + 1) MOD MaxSize
        Queue[ShiftIndex] = Queue[NextIndex] // Overwrite with the next element
        ShiftIndex = NextIndex
        
    // 3. Update REAR and Clear the Old Slot
    Queue[REAR] = NULL // Clear the value that was moved out of the queue
    REAR = (REAR - 1 + MaxSize) MOD MaxSize // Decrement REAR pointer
    
    RETURN "Deletion successful. New REAR is at index: " + REAR
