#include <iostream>
#include <stack>
using namespace std;

struct Node {

    char data;
    Node *left,*right;
};

Node* create(char val) {

    Node* temp=new Node();

    temp->data=val;

    temp->left=temp->right=NULL;

    return temp;
}

int main() {

    string postfix;

    cin>>postfix;

    stack<Node*> s;

    for(char ch: postfix) {

        if(isalnum(ch)) {

            s.push(create(ch));
        }

        else {

            Node* op=create(ch);

            op->right=s.top();
            s.pop();

            op->left=s.top();
            s.pop();

            s.push(op);
        }
    }

    cout<<"Expression Tree Created";

    return 0;
}