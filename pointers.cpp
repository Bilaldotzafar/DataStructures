#include <iostream>
#include<string>
using namespace std;

int main(){

    string names[5] = {"Bilal","Affan","Uzair"};

    string *pointer = nullptr;

    pointer = names;

    cout<< pointer << endl;
    cout<< *pointer << endl;

    
}