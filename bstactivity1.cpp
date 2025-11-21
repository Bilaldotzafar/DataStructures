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
        cout<<"inserted as root node";
        return;
    }

    bst *current = root;
    bst *parent = NULL;

    while(current == NULL){
       parent = current;
       
       if(number < current -> id){

        current = current -> left;
       }
       else if(number > current -> id){
        current = current -> right;

      }
     else{
         cout<<"already exist";
           delete newnode;
           return;
 }
    }


    if(number < parent -> id){
        parent -> left = newnode;
        cout<<"inserted at thr left of"<<parent->id;

    }
    else{
        parent -> right = newnode;
        cout<<"inserted at right of"<<parent -> id;
    }

}
  void inorder (bst *node){
    if(node == NULL){
        return;
    }


    inorder(node -> left);
    cout<<node->id;
    inorder(node -> right);
  }





  int mian(){

    insert(50);
    insert(70);
    insert(45);

    inorder(root);

  }