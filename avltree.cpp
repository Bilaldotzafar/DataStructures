#include<iostream>
using namespace std;


struct node{
    int data;
    node *left;
    node *right;
    int ht;

};


int height(node *T){
    int lh,rh;
    if(T ==NULL)

return(0);

if(T->left ==NULL)
lh = 0;
else 
lh = 1+T->left->ht;
if(T->right == NULL)
rh = 0;
else 
rh=1+T->right->ht;
if(lh>rh)
return (lh);
return(rh);
}

int BF(node *T)
{
int lh,rh;
if(T==NULL)
return(0);
if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
return(lh-rh);
}

node * rotateright(node *x)
{
node *y;
y=x->left;
x->left=y->right;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}

node * rotateright(node *x)
{
node *y;
x-> left = NULL;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}