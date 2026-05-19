#include <iostream>
#include <queue>
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

void levelOrder(Node* root) {

    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();

        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

int main() {

    Node* root = NULL;

    int n, val;

    cin >> n;

    for(int i=0; i<n; i++) {

        cin >> val;

        root = insert(root, val);
    }

    levelOrder(root);

    return 0;
}