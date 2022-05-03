

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<long long>v[100005];
bool visited[100005];
long long a[100005];


long long dfs(long long n) {
    long long mn,nd;
    visited[n]=true;
    mn=a[n];
    for(int i=0; i<v[n].size(); i++) {
         nd=v[n][i];
        if(!visited[nd])
            mn = min(mn, dfs(nd));
    }
    return mn;
}

int main() {
    long long m,n,x,y;
    long long ans=0;
    scanf("%lld", &n);
    scanf("%lld", &m);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0; i< m; i++) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<n;i++) {
        if(!visited[i ])
            ans+=dfs(i);
    }
    printf("%lld\n",ans);
    return 0;
}
