#include<iostream>
using namespace std;
class bst{
    public:
    int data;
    bst* left;
    bst* right;
    bst(int val){
        data = val;
        left=right=NULL;
 }
};

 bst* insert(bst* root, int val){
    bst* newNode = new bst(val);

    if(root == NULL)
    return newNode;
    bst* current = root;
    bst* parent = NULL;
    while(current!=NULL){
        parent = current;

        if(val< current->data){
            current = current->left;
        }
        else{
            current = current-> right;
        }
    }
        if(val<parent->data){
            parent->left=newNode;

        }else{
            parent->right = newNode;
        }
        return root;
        
 }

 bst * search(bst* root, int key){
    bst *p = root;
    while(p!=NULL && p->data!=key){
        if(key>p->data)
        p = p->right;
    else
    p = p->left;
    }
    return p;
 }

 bst * min(bst* root){

    bst *p = root, *p2;
    while(p!=NULL){

        p2 = p;
        p = p->left;
    }
    return p2;
}

bst * max(bst* root){
    bst * p = root, *p2;
    while(p!=NULL)
    {
        p2 = p;
        p = p->right;
    }
    return p2;
}








int main(){

    bst* root = NULL;

    root = insert(root,50);
    root = insert(root,60);
   


}