#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    int val,height;
    node* left;
    node* right;

    public:
    node(int n)
    {
        val = n;
        height = 0;
        left = right = NULL;
    }
    friend class AVL;
};

class AVL{

    public:

    int height(node* p){
        if(p==NULL)
        {
            return 0;
        }
        return p->height;
    }

    int max(int a, int b)
    {
        return a>b?a:b;
    }

    node* newNode(int x)
    {
        node* temp = new node(x);
        temp->height = 1;
        return temp;
    }

    
    node* LeftRot(node* y)
    {
        node* x = y->right;
        node* t = x->left;

        //rotation 
        x->left = y;
        y->right = t;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return x;
    }
    node* RightRot(node* y){
        node* x = y->left;
        node* t = x->right;

        //rotation 
        x->right = y;
        y->left = t;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return x;
    }

    int getBalance(node* x)
    {
        if(x==NULL)
        {
            return 0;
        }
        return height(x->left)-height(x->right);
    }

    node* insertNode(node* root,int x)
    {
        if(root==NULL)
        {
            return newNode(x); 
        }

        if(x<root->val)
        {
            root->left = insertNode(root->left,x);
        }
        else if(x>root->val)
        {
            root->right = insertNode(root->right,x);
        }
        else
        return root;

        root->height = 1 + max(height(root->left),
                        height(root->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && x < root->left->val)
        return RightRot(root);
 
    // Right Right Case
    if (balance < -1 && x > root->right->val)
        return LeftRot(root);
 
    // Left Right Case
    if (balance > 1 && x> root->left->val)
    {
        root->left = LeftRot(root->left);
        return RightRot(root);
    }
 
    // Right Left Case
    if (balance < -1 && x < root->right->val)
    {
        root->right = RightRot(root->right);
        return LeftRot(root);
    }
 
    /* return the (unchanged) node pointer */
    return root;

    }

    void preorder(node* p)
    {
        if(p!=NULL)
        {
            cout<<p->val<<":"<<p->height<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    
};

int main()
{
    node * root = NULL;
    AVL o;

    while (1)
    {
        int choice;
        int num;
        cout << endl
             << "\t\tMENU" << endl;
        cout << "1. Insert node\n2. Preorder\n3. EXIT\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter value to insert: ";cin>>num;
                
            root = o.insertNode(root,num);
            cout << endl;
            break;
        case 2:
        cout << endl
                 << "------------------------------" << endl;
            cout << "Preorder:";
            o.preorder(root);
            cout << endl
                 << "------------------------------" << endl;
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
    }
    
    return 0;
}