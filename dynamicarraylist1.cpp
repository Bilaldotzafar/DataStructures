#include <iostream>
using namespace std;
class dynamicarray{
    private:
    int* arr;
    int size;
    int capacity;


    void resize(){

        int newcapacity = capacity * 2;
        int* newarray = new int[newcapacity];


        for(int i=0; i<size; i ++){

            newarray[i] = arr[i];

        }

        delete [] arr;
        arr = newarray;
        capacity = newcapacity;

    }
    public:
    dynamicarray (){

        capacity = 7;
        arr = new int[capacity];
        size = 0;
    }

   ~dynamicarray(){

        delete [] arr;
    }

    void insertatend (int value){
        if(size == capacity){
            resize();
        }
        arr[size++] = value;

    }

    void insertatstart ( int value){
        if(size == capacity){
            resize();
        }

        for(int i = size; i > 0; i--){

            arr[i] = arr[i-1];
        }
        arr[0] = value;
        size++;
    }


    void aftervalue(int specific , int value){
        if(size == capacity){
            resize();
        }
        for(int i = 0; i < size; i++){
            if(specific == arr[i]){
            for(int j = size; j > i + 1; j--){
                arr[j] = arr[j-1];
            }
            arr[i +1] = value;
            size++;

            }
        }
    }

      void Beforevalue(int specific, int value){
    if(size >= capacity){
        resize();
    }
    
    for(int i = 0; i < size; i++){
        if(arr[i] == specific){
            
            for(int j = size; j > i; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = value;
            size++;
            break;   
        }
    }
}
    
    
    void display() {
        cout << "ArrayList: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main(){

    dynamicarray list1;
    list1.insertatend(10);
    list1.insertatend(20);
    list1.insertatend(30);
    list1.Beforevalue(20,90);
    list1.display();
    
}