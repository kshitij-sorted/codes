#include <iostream>
using namespace std;

struct Node {

    int data;
    Node *left,*right;
};

Node* create(int val) {

    Node* temp=new Node();

    temp->data=val;

    temp->left=temp->right=NULL;

    return temp;
}

Node* insert(Node* root,int val) {

    if(root==NULL)
        return create(val);

    if(val<root->data)
        root->left=insert(root->left,val);

    else
        root->right=insert(root->right,val);

    return root;
}

int height(Node* root) {

    if(root==NULL)
        return 0;

    return max(height(root->left),
               height(root->right))+1;
}

bool balanced(Node* root) {

    if(root==NULL)
        return true;

    int left=height(root->left);
    int right=height(root->right);

    if(abs(left-right)>1)
        return false;

    return balanced(root->left)
           &&
           balanced(root->right);
}

int main() {

    Node* root=NULL;

    int n,val;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>val;

        root=insert(root,val);
    }

    if(balanced(root))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";

    return 0;
}