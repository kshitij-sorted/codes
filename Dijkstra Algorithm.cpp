#include <iostream>
using namespace std;

int main() {

    int n;

    cin>>n;

    int graph[10][10];

    for(int i=0;i<n;i++) {

        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    }

    int source;

    cin>>source;

    int dist[10],visited[10]={0};

    for(int i=0;i<n;i++)
        dist[i]=999;

    dist[source]=0;

    for(int count=0;count<n-1;count++) {

        int min=999,u;

        for(int i=0;i<n;i++) {

            if(!visited[i] &&
               dist[i]<min) {

                min=dist[i];
                u=i;
            }
        }

        visited[u]=1;

        for(int v=0;v<n;v++) {

            if(!visited[v] &&
               graph[u][v] &&
               dist[u]+graph[u][v]
               < dist[v]) {

                dist[v]=dist[u]
                        +graph[u][v];
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";

    return 0;
}