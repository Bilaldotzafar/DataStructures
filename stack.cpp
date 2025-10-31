#include <iostream>
using namespace std;

class stack {
private:

    int tos;
    char values[100];


public:

    stack(int x){

        tos = -1;
        values[x];
    }
    void push(char x){
        if(tos == 99){

            cout << "stack overflow condition"  << endl;
    }
        else{
            values[++tos] = x;
        }
    }

    char pop(){

        if(tos == -1){
            cout<< "stack underflow condition" << endl;
            return ' ';

        }
        else{
            return values[tos--];

        }
    }
    
};
int main(){

    stack * newstack = new stack(10);

    newstack-> push('A');
    newstack -> push('B');
    newstack -> pop();
    newstack -> pop();
    newstack -> pop();


}
