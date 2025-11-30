#include <iostream>
using namespace std;


struct node {
    int key;
    int data;
    int ht;
    node *left;
    node *right;
};


int height(node *T) {
    int lh, rh;
    if(T == NULL)
        return 0;
    
    if(T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    
    if(T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    
    if(lh > rh)
        return lh;
    return rh;
}


int BF(node *T) {
    int lh, rh;
    if(T == NULL)
        return 0;
    
    if(T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    
    if(T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    
    return (lh - rh);
}


node* rotateright(node *x) {
    node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}


node* rotateleft(node *x) {
    node *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}


node* LL(node *T) {
    T = rotateright(T);
    return T;
}

node* RR(node *T) {
    T = rotateleft(T);
    return T;
}


node* LR(node *T) {
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return T;
}


node* RL(node *T) {
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return T;
}

node* insert(node *T, int x) {
    if(T == NULL) {
        T = new node;
        T->key = x;
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 0;
    }
    else if(x > T->key) {
        T->right = insert(T->right, x);
        if(BF(T) == -2) {
            if(x > T->right->key)
                T = RR(T);
            else
                T = RL(T);
        }
    }
    else if(x < T->key) {
        T->left = insert(T->left, x);
        if(BF(T) == 2) {
            if(x < T->left->key)
                T = LL(T);
            else
                T = LR(T);
        }
    }
    
    T->ht = height(T);
    return T;
}


void Inorder(node *root) {
    if(root != NULL) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}


void displayTree(node *root, int space = 0, int height = 10) {
    if(root == NULL)
        return;
    
    space += height;
    displayTree(root->right, space);
    cout << endl;
    
    for(int i = height; i < space; i++)
        cout << " ";
    cout << root->key << "(h=" << root->ht << ", BF=" << BF(root) << ")";
    
    displayTree(root->left, space);
}

int main() {
    node *root = NULL;
    int values[] = {13, 8, 5, 9, 4, 6, 12, 2, 1, 3};
    int n = 10;
    
    cout << "========================================" << endl;
    cout << "  PROBLEM 1: AVL TREE INSERTION" << endl;
    cout << "========================================" << endl;
    cout << "\nInserting values in order: 13, 8, 5, 9, 4, 6, 12, 2, 1, 3\n";
    cout << "Tree notation: value(h=height, BF=balance factor)\n" << endl;
    
    for(int i = 0; i < n; i++) {
        cout << "\n========================================" << endl;
        cout << "Step " << (i + 1) << ": Inserting " << values[i] << endl;
        cout << "========================================" << endl;
        
        root = insert(root, values[i]);
        
        cout << "\nTree Structure (rotated 90° clockwise):" << endl;
        displayTree(root);
        
        cout << "\n\nInorder Traversal: ";
        Inorder(root);
        cout << endl;
        
        cout << "Root: " << root->key;
        cout << ", Height: " << root->ht;
        cout << ", Balance Factor: " << BF(root) << endl;
    }
    
    cout << "\n========================================" << endl;
    cout << "  FINAL AVL TREE" << endl;
    cout << "========================================" << endl;
    displayTree(root);
    cout << "\n\nInorder Traversal: ";
    Inorder(root);
    cout << endl;
    
    return 0;
}