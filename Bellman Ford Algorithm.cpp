#include <iostream>
using namespace std;

struct Edge {

    int u,v,w;
};

int main() {

    int vertices,edges;

    cin>>vertices>>edges;

    Edge edge[100];

    for(int i=0;i<edges;i++) {

        cin>>edge[i].u
            >>edge[i].v
            >>edge[i].w;
    }

    int source;

    cin>>source;

    int dist[100];

    for(int i=0;i<vertices;i++)
        dist[i]=999;

    dist[source]=0;

    for(int i=1;i<vertices;i++) {

        for(int j=0;j<edges;j++) {

            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;

            if(dist[u]!=999 &&
               dist[u]+w<dist[v])

                dist[v]=dist[u]+w;
        }
    }

    for(int i=0;i<vertices;i++)
        cout<<dist[i]<<" ";

    return 0;
}