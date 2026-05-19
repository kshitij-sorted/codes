#include <iostream>
#include <stack>
using namespace std;

struct Node {

    char data;
    Node *left,*right;
};

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

        cout<<curr->data;

        curr=curr->right;
    }
}

int main() {

    cout<<"Non Recursive Traversal";

    return 0;
}