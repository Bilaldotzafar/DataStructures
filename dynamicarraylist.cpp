#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;     
    int size;     
    int capacity; 

    
    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;    
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        capacity = 5;   
        arr = new int[capacity];
        size = 0;
    }

    ~DynamicArray() {
        delete[] arr; 
    }

  
    void insertEnd(int value) {
        if (size == capacity) resize();
        arr[size++] = value;
    }

 
    void insertStart(int value) {
        if (size == capacity) resize();
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    
    void insertAfter(int afterValue, int newValue) {
        if (size == capacity) resize();
        for (int i = 0; i < size; i++) {
            if (arr[i] == afterValue) {
                for (int j = size; j > i + 1; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i + 1] = newValue;
                size++;
                return;
            }
        }
        cout << "Value not found!\n";
    }

    
    void insertBefore(int beforeValue, int newValue) {
        if (size == capacity) resize();
        for (int i = 0; i < size; i++) {
            if (arr[i] == beforeValue) {
                for (int j = size; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i] = newValue;
                size++;
                return;
            }
        }
        cout << "Value not found!\n";
    }


    void insertAtIndex(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index!\n";
            return;
        }
        if (size == capacity) resize();
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

  
    void display() {
        cout << "ArrayList: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    
    void deleteEnd() {
        if (size > 0) size--;
        else cout << "List is empty!\n";
    }

    
    void deleteStart() {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else cout << "List is empty!\n";
    }

   
    void deleteValue(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                return;
            }
        }
        cout << "Value not found!\n";
    }

    
    int linearSearch(int value) {
        int i = 0;
        while (i < size) {
            if (arr[i] == value) {
                return i; 
            }
            i++;
        }
        return -1; 
    }
};

int main() {
    DynamicArray list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.display();  

    list.insertStart(5);
    list.display();  

    list.insertAfter(20, 25);
    list.display();  

    list.insertBefore(10, 9);
    list.display();   

    list.insertAtIndex(2, 15);
    list.display();  

    list.deleteEnd();
    list.display();   

    list.deleteStart();
    list.display();   

    list.deleteValue(15);
    list.display();   

    int target = 25;
    int pos = list.linearSearch(target);
    if (pos != -1)
        cout << "Value " << target << " found at index " << pos << endl;
    else
        cout << "Value " << target << " not found!\n";

    return 0;
}