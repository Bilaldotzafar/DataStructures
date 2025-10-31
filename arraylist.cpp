#include<iostream>
using namespace std;


    class Arraylist {
        int arr[120];
        int size;


    public:
        Arraylist() {
            size = 0;
        }
    

  void insertatend(int value){
   arr[size++] = value;

  }

  void print(){   
    for(int i = 0; i < size; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
  }

   void insertatfirst(int value) {

    if(size == 99){
            cout<<"Array full";
            return;
    }else{
        
        for(int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        
        arr[0] = value;
        size++;
        
    }}

   void insertafter(int specific,int value){

        for(int i = 0; i < size; i++){  
            if(arr[i]==specific){
                for(int j = size; j > i + 1; j--){
                    arr[j] = arr[j-1];  
                }
                arr[i + 1] = value;
                size++;
                break;  
            }
        }
    }

void insertbefore (int specific,int value){

        for(int i = 0; i < size ; i++){
            if(arr[i]==specific){

                for(int j = size;  j > i; j--){
                    arr[j] = arr[j-1];
                    
                }
                arr[i] = value;
                size++;
                break;
            }
        }
    }

     void deleteatlast(){
        if (size == 0){
            cout<<"Array empty";
        }
        else{
                size--;
            }
        }

        void deletefromstart(){
            if (size == 0){
                cout<<"Array empty";
            }
            else{
                for(int i = 0; i < size - 1; i++){
                    arr[i] = arr[i + 1];
                }
                size--;
            }
        }
     
    





};
    int main(){
        Arraylist list;
        list.insertatend(5);
        list.insertatend(10);
    list.insertatend(15);
    list.insertafter(5,7);
    list.insertbefore(10,8);
    list.deleteatlast();
        
        list.print();

        
        return 0;
        


    }
    

