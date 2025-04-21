/**
    @author: ddi4z
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// integer vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// vectors of vectors of integers
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// pairs of integers
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

// vector of pairs of integers
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// stack of integers
typedef stack<int> si;

// stack of pairs of integers
typedef stack<pii> spii;

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fori(i, s, n) for(int i = s; i < n; ++i)
#define rfori(i, s, n) for(int i = s; i >= n; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 1;
const ld EPS = 1e-9;

#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

// order statistics

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set order;


int mod(int a, int m) {return ((a%m) + m) % m;}

struct Edge {
    ll v, flow, cap;
    ll rev;
};

vector<vector<Edge>> adj;
vll level, ptr;
ll n, m;

void addEdge(ll u, ll v, ll cap) {
    Edge a{v, 0, cap, (ll)adj[v].size()};
    Edge b{u, 0, 0, (ll)adj[u].size()};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool bfs(ll s, ll t) {
    level.assign(n, -1);
    level[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto &e : adj[u]) {
            if (level[e.v] < 0 && e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level[t] != -1;
}

ll dfs(ll u, ll t, ll pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;
    for (; ptr[u] < adj[u].size(); ++ptr[u]) {
        Edge &e = adj[u][ptr[u]];
        if (level[e.v] == level[u] + 1 && e.flow < e.cap) {
            ll tr = dfs(e.v, t, min(pushed, e.cap - e.flow));
            if (tr > 0) {
                e.flow += tr;
                adj[e.v][e.rev].flow -= tr;
                return tr;
            }
        }
    }
    return 0;
}

ll dinic(ll s, ll t) {
    ll flow = 0;
    while (bfs(s, t)) {
        ptr.assign(n, 0);
        while (ll pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    scanf("%lld %lld", &n, &m);
    adj.assign(n, vector<Edge>());
    fori(i,0,m) {
        ll u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        --u; --v;
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
    ll s = 0, t = n - 1;
    printf("%lld\n", dinic(s, t));
    return 0;
}
