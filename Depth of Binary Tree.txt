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

int height(Node* root) {

    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {

    Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);

    cout << "Height of Tree = "
         << height(root);

    return 0;
}