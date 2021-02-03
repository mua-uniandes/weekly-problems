#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int n;
int a[200005], b[200005], pa[200005];
ll ans[200005];
int q;
vector<int> g[200005];
void dfs(int x, ll cum){
    ans[x]+=cum;
    for(int y:g[x]){
        if(y==pa[x])continue;
        dfs(y,ans[x]);
    }
}
void dfs2(int x, int pp){
    pa[x]=pp;
    for(int i =0; i<g[x].size(); ++i){
        if(g[x][i]!=pa[x]){
            dfs2(g[x][i],x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<n;++i){
        cin>>a[i]>>b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    int root = 1;
    dfs2(root,1);
    cin>>q;
    while(q--){
        int t,e,x;
        cin>>t>>e>>x;
        if(t==1){
            if(a[e]==pa[b[e]]){
                ans[root]+=x;
                ans[b[e]]-=x;
            }
            else{
                ans[a[e]]+=x;
            }
        }
        else{
            if(a[e]==pa[b[e]]){
                ans[b[e]]+=x;
            }
            else{
                ans[root]+=x;
                ans[a[e]]-=x;
            }
        }
    }
    dfs(root,0LL);
    for(int i=1;i<=n; ++i){
        cout<<ans[i]<<"\n";
    }
    return 0;
}