#include <iostream>
using namespace std;

int main() {

    int n;

    cin>>n;

    int comments[n];

    for(int i=0;i<n;i++)
        cin>>comments[i];

    int maxIndex=0;
    int minIndex=0;

    for(int i=1;i<n;i++) {

        if(comments[i]>comments[maxIndex])
            maxIndex=i;

        if(comments[i]<comments[minIndex])
            minIndex=i;
    }

    cout<<"Maximum Comments User: "
        <<maxIndex<<endl;

    cout<<"Minimum Comments User: "
        <<minIndex;

    return 0;
}