
#include<bits/stdc++.h>
using namespace std;


const int maxm=2e5+5;
int pre[maxm];

struct Node{
    int a,b,c;
}e[maxm];

vector<pair<int, int>> g[maxm];

int mark[maxm];
int ans[maxm];
int n,m;;
int ffind(int x){
    return pre[x]==x ? x : pre[x]=ffind(pre[x]);
}

void dfs(int x,int fa){
    for(auto i:g[x]){
        int v=i.first;
        int w=i.second;
        if(v==fa)continue;
        if(ans[x]==w)
            ans[v]=(w-1>=1?w-1:w+1);
        else
            ans[v]=w;
        dfs(v,x);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        e[i]={a,b,c};
    }
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x=ffind(e[i].a);
        int y=ffind(e[i].b);
        if(x==y)continue;
        mark[i]=1;
        pre[x]=y;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(pre[i]==i){
            sum++;
        }
    }
    if(sum!=1){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(mark[i]){
            g[e[i].a].push_back({e[i].b,e[i].c});
            g[e[i].b].push_back({e[i].a,e[i].c});
        }
    }
    ans[1]=1;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
