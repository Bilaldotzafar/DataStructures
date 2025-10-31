#include <iostream>
using namespace std;


class Node{
    public:

    int data;
    Node* next;


    Node(int value){
        data = value;
        next = NULL;
    }


};

class LinkedList{

    Node* head;
    Node* tail;

    public:
    LinkedList(){
        head = tail = NULL;
    }



    void push_front(int value){

        Node* newNode = new Node(value);

        if(head == NULL){

            head = tail = newNode;
        }else{

            newNode->next = head;
            head = newNode;
        }

       
    }


    void push_back(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
        head = tail = newNode;
        }
        else{

        tail -> next = newNode;
        tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<< "list is empty";
        
        }else{

            Node * temp = head;
            head = head -> next;
            temp ->next  = NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(head == NULL){

        cout << "List is empty";
    }
    Node* temp = head;
     while(temp -> next != tail){
            temp = temp -> next;
        }
         
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void insertinmiddle(int value,int position){

        Node * newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
    }   Node * temp = head;

    for(int i = 1; i< position ; i++){
        temp = temp->next;

    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void search(int key){

    Node* temp = head;
    int index = 0;
    while(temp != NULL){

        if(temp -> data == key){
            cout<< "Key found at index: " << index << endl;
            return;
        }
        temp = temp -> next;
        index++;



    }
}

   LinkedList mergeLists(LinkedList& a, LinkedList& b){
        LinkedList c;
        c.head = a.head;
        c.tail = a.tail;
        if(a.tail != NULL){
            a.tail->next = b.head;
        }else{
            c.head = b.head;
        }
        if(b.tail != NULL){
            c.tail = b.tail;
        }
        return c;
    }



    void display(){

        Node * temp = head;
        while(temp != NULL){
            cout<< temp-> data << "->";
            temp = temp-> next;


        }
        cout<< "NULL" << endl;
    }








};

int main(){
    

    LinkedList a;
    LinkedList b;

    a.push_front(5);
   a.push_front(10);
    a.push_back(15);
    //list.pop_front();
    //list.pop_back();
   a.insertinmiddle(12,1);
  a.search(15);
   a.display();


   b.push_front(5);
   b.push_front(10);
    b.push_back(15);
    //list.pop_front();
    //list.pop_back();
   b.insertinmiddle(12,1);
  b.search(15);
   a.display();







}