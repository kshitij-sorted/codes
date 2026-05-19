#include <iostream>
#include <list>
using namespace std;

int main() {

    int size;

    cin>>size;

    list<int> hash[size];

    int n,key;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>key;

        int index=key%size;

        hash[index].push_back(key);
    }

    for(int i=0;i<size;i++) {

        cout<<i<<" -> ";

        for(int x:hash[i])
            cout<<x<<" ";

        cout<<endl;
    }

    return 0;
}