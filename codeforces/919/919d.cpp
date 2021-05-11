#include<bits/stdc++.h>
#define ll long long
using namespace std;

int MAX = 300001;

char see[300001];
vector<int> marked;
vector<vector<int>> g;
vector<vector<int>> dp;

bool cycle(int n){
    marked[n] = 0;

    bool ans = 0;

    for(auto adj:g[n]){
        if(marked[adj] == -1) ans = ans | cycle(adj);
        else if(marked[adj] == 0) return true;
    }

    marked[n] = 2;
    return ans;
}


vector<int> dfs(int n){
    if(marked[n]) return dp[n];
    marked[n] = 1;
    vector<int> temp(26,0);
    for(auto adj:g[n]){
        vector<int> see = dfs(adj);
        for(int i = 0; i < 26;++i)
            temp[i] = max(temp[i],see[i]);
    }
    ++temp[see[n]-'a'];
    return dp[n] = temp;
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    scanf(" %s",see);
    marked.resize(n,-1);
    g.resize(n);
    dp.resize(n,vector<int>(26,0));
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
    }
    bool ans = 0;
    for(int i = 0; i < n && !ans;++i){
        if(marked[i] == -1)
            ans = ans | cycle(i);
    }
    if(ans){puts("-1");return 0;}
    fill(marked.begin(),marked.end(),0);
    for(int i = 0; i < n;++i){
        if(!marked[i]){
            dfs(i);
        }
    }
    int lel = 0;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < 26;++j)
            lel = max(lel,dp[i][j]);
    }
    printf("%d\n",lel);
    return 0;
}