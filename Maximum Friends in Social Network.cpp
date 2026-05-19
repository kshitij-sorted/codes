#include <iostream>
#include <vector>
using namespace std;

int main() {

    int users,edges;

    cin>>users>>edges;

    vector<int> degree(users,0);

    for(int i=0;i<edges;i++) {

        int u,v;

        cin>>u>>v;

        degree[u]++;
        degree[v]++;
    }

    int maxUser=0;

    for(int i=1;i<users;i++) {

        if(degree[i]>degree[maxUser])
            maxUser=i;
    }

    cout<<"User with Maximum Friends: "
        <<maxUser;

    return 0;
}