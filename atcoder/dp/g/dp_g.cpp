#include "bits/stdc++.h"
using namespace std;

// DAG - directed acyclic graph

const int nax = 1e5 + 5;
vector<int> edges[nax];
int in_degree[nax]; // the number of edges going to 'b'
int dist[nax];
bool visited[nax];

void dfs(int a) {
    assert(!visited[a]);
    visited[a] = true;
    for(int b : edges[a]) {
        dist[b] = max(dist[b], dist[a] + 1);
        --in_degree[b];
        if(in_degree[b] == 0) {
            dfs(b);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        ++in_degree[b];
    }
    for(int i = 1; i <= n; ++i) {
        if(!visited[i] && in_degree[i] == 0) {
            dfs(i);
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        answer = max(answer, dist[i]);
    }
    printf("%d\n", answer);
}