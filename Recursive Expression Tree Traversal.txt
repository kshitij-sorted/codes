#include <iostream>
using namespace std;

struct Node {

    char data;
    Node *left,*right;
};

void inorder(Node* root) {

    if(root) {

        inorder(root->left);

        cout<<root->data;

        inorder(root->right);
    }
}

void preorder(Node* root) {

    if(root) {

        cout<<root->data;

        preorder(root->left);

        preorder(root->right);
    }
}

void postorder(Node* root) {

    if(root) {

        postorder(root->left);

        postorder(root->right);

        cout<<root->data;
    }
}

int main() {

    cout<<"Expression Tree Traversals";

    return 0;
}