//
//  abc146_d.cpp
//  Problems
//
//  Created by NicolasCardozo on 2/23/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, a, b;
    vector<pair<int,int>> edges;
    cin >> n;
    vector<vector<int>> graph(n+1);
    
    for(int i=1; i<n; i++) {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        edges.emplace_back(a,b);
    }
    
    vector<int> colors(n+1, 0);
    vector<int> used(n+1, 0);
    map<pair<int,int>, int> edgeColor;
    queue<int> queue;
    int k = 0;
    used[1] = 1;
    queue.push(1);
    while(!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        if(k < (int)graph[vertex].size())
            k = (int)graph[vertex].size();
        int current = 1;
        for(int u : graph[vertex]) {
            if(used[u]) continue;
            if(current == colors[vertex])
                current++;
            colors[u] = edgeColor[make_pair(u,vertex)] = edgeColor[make_pair(vertex,u)] = current++;
            used[u] = 1;
            queue.push(u);
        }
    }
    cout << k << endl;
    for(auto p : edges)
        cout << edgeColor[p] << endl;
    return 0;
}
