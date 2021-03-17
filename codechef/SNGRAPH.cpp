//
//  SNGRAPH.cpp
//  Problems
//
//  Created by NicolasCardozo on 3/15/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//


#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;

const int N = 1e5 + 5;

vector<int> graph[N], nodes[N];
int degree[N], parent[N], size[N], ans[N];
bool active[N];
int components;

int par(int x){
    if(parent[x] != x)
        parent[x] = par(parent[x]);
    return parent[x];
}

void dsu(int a, int b){
    int p1 = par(a), p2 = par(b);
    if(p1 == p2)
        return ;
    if(size[p1] < size[p2])
        swap(p1, p2);
    size[p1] += size[p2];
    parent[p2] = p1;
    components--;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        for(int i = 0; i < N; i++){
            graph[i].clear();
            nodes[i].clear();
            degree[i] = 0;
            active[i] = 0;
        }

        int n, m, u, v;
        cin >> n >> m;
        while(m--){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        components = n;
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
            nodes[degree[i]].push_back(i);
        }

        for(int i = n - 1; i >= 0; i--){
            ans[i] = components - 1;
            for(auto u : nodes[i])
                active[u] = 1;
            for(auto u : nodes[i]){
                for(auto v : graph[u]){
                    if(active[v] == 0)
                        continue;
                    dsu(u, v);
                }
            }
        }

        for(int i = 0; i < n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
