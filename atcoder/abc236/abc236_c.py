//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)\
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")\
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5+5;
const ld eps = 1e-9;
const int mod = 1e9+7;
const ll INF = 1e18;

int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,  a, b, h;
    cin>>n>>m;
    vector<string> v1(n), v2(m);
    set<string > conj;
    for(int i = 0; i<n; ++i) cin>>v1[i];
    for(int i = 0; i<m; ++i) cin>>v2[i];
    for(auto x: v2) conj.insert(x);
    for(auto x: v1){
        if(conj.count(x)) cout<<"Yes\n";
        else cout<<"No\n";
    }


}