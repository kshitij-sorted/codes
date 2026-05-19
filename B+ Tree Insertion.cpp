#include <iostream>
#include <vector>
using namespace std;

class BPlusTree {

    vector<int> data;

public:

    void insert(int val) {

        data.push_back(val);

        for(int i=0;i<data.size();i++) {

            for(int j=i+1;j<data.size();j++) {

                if(data[i]>data[j])
                    swap(data[i],data[j]);
            }
        }
    }

    void display() {

        for(int x:data)
            cout<<x<<" ";
    }
};

int main() {

    BPlusTree b;

    int n,val;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>val;

        b.insert(val);
    }

    b.display();

    return 0;
}