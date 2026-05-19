#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
bool visited[100];

void bfs(int start) {

    queue<int> q;

    q.push(start);

    visited[start]=true;

    while(!q.empty()) {

        int node=q.front();

        q.pop();

        cout<<node<<" ";

        for(int child: graph[node]) {

            if(!visited[child]) {

                visited[child]=true;

                q.push(child);
            }
        }
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

    bfs(start);

    return 0;
}