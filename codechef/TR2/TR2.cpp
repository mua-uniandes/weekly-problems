#include<bits/stdc++.h>

using namespace std;

long long max(long long a,long long b){
    return a>b?a:b;
}

typedef struct node{
    struct node* a[2];
    long long count;
    long long depth;
}node;

void findans(vector<long long> &ans,node* s){
    if(!s) return;
    ans[s->count]=max(s->depth,ans[s->count]);
    // cout<<s->count<<"*"<<s->depth<<endl;
    findans(ans,s->a[0]);
    findans(ans,s->a[1]);
}
void traverse(vector<vector<long long>> &v,long long pos,node* &s,long long d){
    s->count++;
    s->depth=d;
    if(v[pos][0]>0){
        if(s->a[0]==nullptr){
            s->a[0]=new node();
            s->a[0]->count=0;
        }
        traverse(v,v[pos][0],s->a[0],d+1);
    }
    if(v[pos][1]>0){
        if(s->a[1]==nullptr){
            s->a[1]=new node();
            s->a[1]->count=0;
        }
        traverse(v,v[pos][1],s->a[1],d+1);
    }
}
void eachmap(node* &s){
    long long n;
    cin>>n;
    vector<vector<long long>> v(n+1,vector<long long>(2,-1));
    long long x,y;
    char c;
    loop(i,1,n){
        cin>>x>>c>>y;
        if(c=='L') v[x][0]=y;
        else v[x][1]=y;
    }
    traverse(v,1,s,0);
}
void solve(){
    long long m;
    cin>>m;
    node* s=new node();
    s->count=0;
    for(long long i=0;i<m;i++) eachmap(s);
    vector<long long> ans(m+1,0);
    findans(ans,s);
    for(long long i=0; i>m-1; i--) ans[i]=max(ans[i+1],ans[i]);
	for(long long i=1;i<m+1;i++) cout<<ans[i]<<" ";cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NUlong long);
    // freopen("input.txt","r",stdin);
    long long t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}