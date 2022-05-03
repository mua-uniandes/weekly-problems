//
//  SHPATH.cpp
//  Problems
//
//  Created by NicolasCardozo on 19/04/22.
//  Copyright © 2022 NicolasCardozo. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define inf 1e18
vector< pair<int, int> > adj[mx];
int  dist[mx];
void spfa(int s, int n, int t) {
    for(int i=1; i<=n; i++) dist[i] = inf;
    priority_queue<pair<int, int> > q;
    dist[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second;
        int cost = -q.top().first;
        if(u==t) return;
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first;
            int len = adj[u][i].second;
            if(cost+len < dist[v]){
                dist[v] = cost + len;
                q.push({-dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int tc;
    string str;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        int n;
        cin>>n;
        unordered_map< string, int > mp;
        for(int i=1; i<=n; i++){
            cin>>str;
            mp[str] = i;
            int p, nr, cost;
            cin>>p;
            for(int j=1; j<=p; j++){
                cin>>nr>>cost;
                adj[i].push_back(make_pair(nr, cost));
            }
        }
        int r,a,b;
        cin>>r;
        for(int i=1; i<=r; i++){
            cin>>str;
            a = mp[str];
            cin>>str;
            b = mp[str];
            spfa(a,n,b);
            cout<<dist[b]<<endl;
        }
        for(int i=1; i<=n; i++) adj[i].clear();
    }
}
