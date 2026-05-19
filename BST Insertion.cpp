#include <iostream>
using namespace std;

struct Node {

    int data;
    Node *left, *right;
};

Node* createNode(int val) {

    Node* temp = new Node();

    temp->data = val;
    temp->left = temp->right = NULL;

    return temp;
}

Node* insert(Node* root, int val) {

    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);

    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {

    if(root != NULL) {

        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

int main() {

    Node* root = NULL;

    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {

        cout << "Enter value: ";
        cin >> val;

        root = insert(root, val);
    }

    cout << "\nBST Inorder: ";

    inorder(root);

    return 0;
}