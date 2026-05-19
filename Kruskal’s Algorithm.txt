#include <iostream>
using namespace std;

int parent[10];

int find(int i) {

    while(parent[i])
        i=parent[i];

    return i;
}

int uni(int i,int j) {

    if(i!=j) {

        parent[j]=i;

        return 1;
    }

    return 0;
}

int main() {

    int n;

    cin>>n;

    int cost[10][10];

    for(int i=0;i<n;i++) {

        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }

    int edges=0,mincost=0;

    while(edges<n-1) {

        int min=999,a,b;

        for(int i=0;i<n;i++) {

            for(int j=0;j<n;j++) {

                if(cost[i][j]<min) {

                    min=cost[i][j];

                    a=i;
                    b=j;
                }
            }
        }

        int u=find(a);
        int v=find(b);

        if(uni(u,v)) {

            cout<<a<<" - "<<b
                <<" : "<<min<<endl;

            mincost+=min;

            edges++;
        }

        cost[a][b]=cost[b][a]=999;
    }

    cout<<"Minimum Cost = "
        <<mincost;

    return 0;
}