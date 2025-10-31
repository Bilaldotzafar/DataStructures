#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    float marks;
    Student* next;
};

class StudentRecordSystem {
private:
    Student* head;
    
public:
    StudentRecordSystem() {
        head = nullptr;
    }
    
    void addAtBeginning(int roll, string name, float marks) {
        Student* newNode = new Student;
        newNode->rollNumber = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = head;
        head = newNode;
        cout << "Student added at beginning" << endl;
    }
    
    void addAtEnd(int roll, string name, float marks) {
        Student* newNode = new Student;
        newNode->rollNumber = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Student added at end" << endl;
    }
    
    void addAtPosition(int pos, int roll, string name, float marks) {
        if (pos == 1) {
            addAtBeginning(roll, name, marks);
            return;
        }
        
        Student* newNode = new Student;
        newNode->rollNumber = roll;
        newNode->name = name;
        newNode->marks = marks;
        
        Student* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of range" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Student added at position " << pos << endl;
    }
    
    void deleteByRoll(int roll) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->rollNumber == roll) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted" << endl;
            return;
        }
        
        Student* current = head;
        while (current->next != nullptr) {
            if (current->next->rollNumber == roll) {
                Student* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Student deleted" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Student not found" << endl;
    }
    
    void searchByName(string name) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Roll: " << temp->rollNumber << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Marks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found" << endl;
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Student* temp = head;
        while (temp != nullptr) {
            cout << "Roll: " << temp->rollNumber << " Name: " << temp->name << " Marks: " << temp->marks << endl;
            temp = temp->next;
        }
    }
};

int main() {
    cout << "SCENARIO 1: Student Record System" << endl;
    cout << "=================================" << endl;
    
    StudentRecordSystem s;
    
    cout << "Adding students:" << endl;
    s.addAtBeginning(101, "Bilal", 85);
    s.display();
    cout << endl;
    
    s.addAtEnd(102, "Affan", 78);
    s.display();
    cout << endl;
    
    s.addAtPosition(2, 103, "Uzair", 92);
    s.display();
    cout << endl;
    
    cout << "Deleting student with roll 102:" << endl;
    s.deleteByRoll(102);
    s.display();
    cout << endl;
    
    cout << "Searching for Bilal:" << endl;
    s.searchByName("Bilal");
    cout << endl;
    
    return 0;
}