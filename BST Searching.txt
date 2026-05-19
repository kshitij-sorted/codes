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

bool search(Node* root, int key) {

    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {

    Node* root = NULL;

    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {

        cin >> val;

        root = insert(root, val);
    }

    cout << "Enter key to search: ";
    cin >> key;

    if(search(root, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}