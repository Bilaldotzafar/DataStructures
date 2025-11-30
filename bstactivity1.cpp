#include<iostream>
using namespace std;


struct bst{

    int id;
    bst *right;
    bst *left;

};


bst *root = NULL;


void insert (int number){
    bst *newnode = new bst;
    newnode-> id = number;
    newnode->left = NULL;
    newnode-> right= NULL;



    if (root == NULL){

        root = newnode;
        cout<<"inserted as root node\n";
        return;
    }

    bst *current = root;
    bst *parent = NULL;

    while(current != NULL){
       parent = current;
       
       if(number < current -> id){

        current = current -> left;
       }
       else if(number > current -> id){
        current = current -> right;

      }
     else{
         cout<<"already exist\n";
           delete newnode;
           return;
 }
    }


    if(number < parent -> id){
        parent -> left = newnode;
        cout<<"inserted at the left of "<<parent->id<<"\n";

    }
    else{
        parent -> right = newnode;
        cout<<"inserted at right of "<<parent -> id<<"\n";
    }

}
  void inorder (bst *node){
    if(node == NULL){
        return;
    }


    inorder(node -> left);
    cout<<node->id<<" ";
    inorder(node -> right);
  }





  int main(){

    insert(50);
    insert(70);
    insert(45);

    inorder(root);

    return 0;

  }