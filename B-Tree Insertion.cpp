#include <iostream>
using namespace std;

class BTreeNode {

    int keys[10];
    int t;
    int n;

public:

    BTreeNode(int temp) {

        t=temp;
        n=0;
    }

    void insert(int k) {

        keys[n]=k;

        n++;

        for(int i=0;i<n;i++) {

            for(int j=i+1;j<n;j++) {

                if(keys[i]>keys[j])
                    swap(keys[i],keys[j]);
            }
        }
    }

    void display() {

        for(int i=0;i<n;i++)
            cout<<keys[i]<<" ";
    }
};

int main() {

    int t,n,val;

    cin>>t;

    BTreeNode b(t);

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>val;

        b.insert(val);
    }

    b.display();

    return 0;
}