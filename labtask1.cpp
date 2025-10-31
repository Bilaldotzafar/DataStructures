#include<iostream>
using namespace std;
int main(){
    int sum = 0;

    int start,end;
    cout<<"enter starting number";
    cin>> start;
    cout<<"enter second number";
    cin>> end;
    for(int i = start; i <= end ; i++){
        
       sum += i*i;
      



    
    }
    cout<< "sum of series is"<< sum<< endl;
    return 0;
    
}