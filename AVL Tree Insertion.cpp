#include <iostream>
using namespace std;

struct Node {

    int data,height;
    Node *left,*right;
};

int getHeight(Node* node) {

    if(node==NULL)
        return 0;

    return node->height;
}

int getBalance(Node* node) {

    if(node==NULL)
        return 0;

    return getHeight(node->left)
           -
           getHeight(node->right);
}

Node* create(int val) {

    Node* temp=new Node();

    temp->data=val;

    temp->left=temp->right=NULL;

    temp->height=1;

    return temp;
}

Node* rightRotate(Node* y) {

    Node* x=y->left;

    Node* t=x->right;

    x->right=y;

    y->left=t;

    y->height=max(getHeight(y->left),
                  getHeight(y->right))+1;

    x->height=max(getHeight(x->left),
                  getHeight(x->right))+1;

    return x;
}

Node* leftRotate(Node* x) {

    Node* y=x->right;

    Node* t=y->left;

    y->left=x;

    x->right=t;

    x->height=max(getHeight(x->left),
                  getHeight(x->right))+1;

    y->height=max(getHeight(y->left),
                  getHeight(y->right))+1;

    return y;
}

Node* insert(Node* node,int key) {

    if(node==NULL)
        return create(key);

    if(key<node->data)
        node->left=insert(node->left,key);

    else
        node->right=insert(node->right,key);

    node->height=1+
    max(getHeight(node->left),
        getHeight(node->right));

    int balance=getBalance(node);

    if(balance>1 && key<node->left->data)
        return rightRotate(node);

    if(balance<-1 && key>node->right->data)
        return leftRotate(node);

    if(balance>1 && key>node->left->data) {

        node->left=leftRotate(node->left);

        return rightRotate(node);
    }

    if(balance<-1 && key<node->right->data) {

        node->right=rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root) {

    if(root) {

        inorder(root->left);

        cout<<root->data<<" ";

        inorder(root->right);
    }
}

int main() {

    Node* root=NULL;

    int n,val;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>val;

        root=insert(root,val);
    }

    inorder(root);

    return 0;
}