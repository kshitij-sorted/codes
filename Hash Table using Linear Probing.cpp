#include <iostream>
using namespace std;

int main() {

    int size;

    cin>>size;

    int hash[size];

    for(int i=0;i<size;i++)
        hash[i]=-1;

    int n,key;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>key;

        int index=key%size;

        while(hash[index]!=-1)
            index=(index+1)%size;

        hash[index]=key;
    }

    for(int i=0;i<size;i++)
        cout<<i<<" -> "
            <<hash[i]<<endl;

    return 0;
}