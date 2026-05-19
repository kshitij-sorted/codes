#include <iostream>
#include <stack>
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

void inorder(Node* root) {

    stack<Node*> s;

    Node* curr=root;

    while(curr!=NULL || !s.empty()) {

        while(curr!=NULL) {

            s.push(curr);

            curr=curr->left;
        }

        curr=s.top();

        s.pop();

        cout<<curr->data<<" ";

        curr=curr->right;
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