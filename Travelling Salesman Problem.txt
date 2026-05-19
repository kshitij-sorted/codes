#include <iostream>
using namespace std;

int visited[10],cost=0;

int graph[10][10];

void tsp(int city,int n) {

    visited[city]=1;

    cout<<city<<" -> ";

    int nextCity=-1;
    int min=999;

    for(int i=0;i<n;i++) {

        if(!visited[i] &&
           graph[city][i]<min &&
           graph[city][i]!=0) {

            min=graph[city][i];

            nextCity=i;
        }
    }

    if(nextCity==-1) {

        cout<<0;

        cost+=graph[city][0];

        return;
    }

    cost+=min;

    tsp(nextCity,n);
}

int main() {

    int n;

    cin>>n;

    for(int i=0;i<n;i++) {

        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    }

    tsp(0,n);

    cout<<"\nMinimum Cost = "
        <<cost;

    return 0;
}