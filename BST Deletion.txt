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

Node* minValue(Node* node) {

    while(node->left != NULL)
        node = node->left;

    return node;
}

Node* deleteNode(Node* root, int key) {

    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        if(root->left == NULL) {

            Node* temp = root->right;

            delete root;

            return temp;
        }

        else if(root->right == NULL) {

            Node* temp = root->left;

            delete root;

            return temp;
        }

        Node* temp = minValue(root->right);

        root->data = temp->data;

        root->right =
        deleteNode(root->right, temp->data);
    }

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

    int n, val, key;

    cin >> n;

    for(int i=0; i<n; i++) {

        cin >> val;

        root = insert(root, val);
    }

    cout << "Enter node to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    inorder(root);

    return 0;
}