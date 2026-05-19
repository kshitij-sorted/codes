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

void leafNodes(Node* root) {

    if(root == NULL)
        return;

    if(root->left == NULL &&
       root->right == NULL)

        cout << root->data << " ";

    leafNodes(root->left);
    leafNodes(root->right);
}

int main() {

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Leaf Nodes: ";

    leafNodes(root);

    return 0;
}