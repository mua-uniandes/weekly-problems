//
//  427C.cpp
//  Problems
//
//  Created by NicolasCardozo on 10/26/21.
//  Copyright © 2021 NicolasCardozo. All rights reserved.
//


#include <bits/stdc++.h>

using namespace std;
 
#define mx 200000
#define mod 1000000007ll
 
vector<int> edge[mx];
int low[mx], dtime[mx], _dfstime, _stack[mx], _size, components[mx], comps;
bool inStack[mx];
 
void tarjan(int u){
    low[u]=dtime[u]=++_dfstime;
    _stack[_size++]=u;
    inStack[u]=true;
 
    for(int i=0; i<edge[u].size(); i++){
        int v=edge[u][i];
        if(dtime[v]==-1) tarjan(v), low[u]=min(low[u],low[v]);
        else if(inStack[v]) low[u]=min(low[u],dtime[v]);
    }
 
    if(dtime[u]==low[u]){
        comps++;
        int v=-1;
        do{
            v=_stack[--_size];
            inStack[v]=false;
            components[v]=comps;
        }while(u!=v);
    }
}
 
void scc(int n){
    comps = _dfstime = _size = 0;
    memset(dtime, -1, sizeof(dtime));
    memset(low, 0, sizeof(low));
    memset(_stack, 0, sizeof(_stack));
    memset(components, 0, sizeof(components));
    memset(inStack, 0, sizeof(inStack));
    for(int i=0; i<n; i++)
        if(dtime[i]==-1) tarjan(i);
}
 
int mini[mx], cnt[mx], cost[mx];
 
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&cost[i]);
        assert(0<=cost[i] && cost[i]<=1000000000);
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        assert(1<=u && u<=n);
        assert(1<=v && v<=n);
        u--,v--;
        edge[u].push_back(v);
    }
    scc(n);
    for(int i=1; i<=comps; i++) mini[i]=2000000000;
    for(int i=0; i<n; i++){
        int c=components[i];
        int w=cost[i];
        if(mini[c]>w) mini[c]=w, cnt[c]=1;
        else if(mini[c]==w) cnt[c]++;
    }
    long long a=0, b=1;
    for(int i=1; i<=comps; i++){
        a += mini[i];
        b *= (long long)(cnt[i]);
        b %= mod;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
