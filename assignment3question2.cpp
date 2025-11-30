#include <iostream>

using namespace std;

#define INT_MIN -2147483648
#define INT_MAX 2147483647

struct node {
    int key;
    int data;
    int height;
    node *left;
    node *right;
};

bool isBST(node *T, int min_k, int max_k) {
    if (T == NULL)
        return true; 
    
    if (T->key <= min_k || T->key >= max_k) 
        return false; 

    bool l = isBST(T->left, min_k, T->key); 
    bool r = isBST(T->right, T->key, max_k);  
    
    return l && r; 
}

bool checkProps(node *T) {
    int lh, rh, max_h, abs_diff;

    if (T == NULL)
        return true;

    if (T->left == NULL)
        lh = 0;
    else
        lh = T->left->height;

    if (T->right == NULL)
        rh = 0;
    else
        rh = T->right->height;

    
    if (lh > rh)
        max_h = lh;
    else
        max_h = rh;

    if (T->height != 1 + max_h)
        return false;

    abs_diff = lh - rh;
    if (abs_diff < 0)
        abs_diff = -abs_diff;
        
    if (abs_diff > 1)
        return false;

    bool l_ok = checkProps(T->left);
    bool r_ok = checkProps(T->right);
    
    return l_ok && r_ok;
}

bool verifyAVL(node *T) {
    int min_k = INT_MIN;
    int max_k = INT_MAX;

    if (!isBST(T, min_k, max_k))
        return false;

   
    if (!checkProps(T))
        return false;

    return true;
}

node* newNode(int k) {
    node* t = new node;
    t->key = k;
    t->data = 0;
    t->height = 1;
    t->left = NULL;
    t->right = NULL;
    return t;
}

int main() {
    
    node *root_valid = newNode(8); 
    root_valid->height = 4; 

    root_valid->left = newNode(4);
    root_valid->left->height = 3;

    root_valid->right = newNode(12);
    root_valid->right->height = 2;

    root_valid->left->left = newNode(2);
    root_valid->left->left->height = 2;

    root_valid->left->right = newNode(5);
    root_valid->left->right->height = 2;

    root_valid->left->left->left = newNode(1);
    root_valid->left->left->right = newNode(3);
    
    root_valid->left->right->right = newNode(6);

    root_valid->right->left = newNode(9);
    root_valid->right->right = newNode(13);

    cout << "--- PROBLEM 2: AVL VERIFICATION ---" << endl;
    cout << "Test 1: Valid AVL Tree" << endl;
    
    if (verifyAVL(root_valid))
        cout << "Result: The tree is a valid AVL Tree." << endl;
    else
        cout << "Result: The tree is INVALID." << endl;

    node *root_unbalanced = newNode(30); 
    root_unbalanced->height = 3; 
    root_unbalanced->left = newNode(20); 
    root_unbalanced->left->height = 2; 
    root_unbalanced->left->left = newNode(10); 
    
    cout << "\nTest 2: Broken Balance Property" << endl;
    if (verifyAVL(root_unbalanced))
        cout << "Result: The tree is VALID." << endl;
    else
        cout << "Result: The tree is INVALID (as expected)." << endl;
        
    return 0;
}