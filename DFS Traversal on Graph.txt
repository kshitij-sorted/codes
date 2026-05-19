#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

void dfs(int node) {

    visited[node]=true;

    cout<<node<<" ";

    for(int child: graph[node]) {

        if(!visited[child])
            dfs(child);
    }
}

int main() {

    int v,e;

    cin>>v>>e;

    for(int i=0;i<e;i++) {

        int u,v;

        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;

    cin>>start;

    dfs(start);

    return 0;
}