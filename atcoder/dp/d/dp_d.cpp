/**
    @author: c4ts0up
    @task: MUA 2023-10 4A
    @url: https://vjudge.net/contest/545370#problem/A
*/

#include <bits/stdc++.h>

using namespace std;

/* TIPOS */
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> sll;
#define endl "\n"

/* FUNCIONES */
#define f(i, s, e) for (ll i=s; i<e; i++)
#define cf(i, s, e) for (ll i=s; i<=e; i++)
#define rf(i, e, s) for(ll i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sort(a) sort(a.begin(), a.end())

/* PRINTS */
template<class T>
void print_v(vector<T> &v) {
    cout << "{";
    for (auto x: v) cout << x << " ";
    cout << "\b}";
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = 105, WMAX = 1e5+5;

ll n, W;
vector <ll> v, w;
ll dp[NMAX][WMAX];
bool vis[NMAX][WMAX];

ll Play(ll idx, ll currcap) {
    // caso base
    if (idx == n) return 0;
    // caso dp
    else if (vis[idx][currcap]) return dp[idx][currcap];
    // caso recursivo
    else {
        ll tomar = -INF, notomar = -INF;
        notomar = Play(idx+1, currcap);
        if (w[idx] <= currcap) tomar = Play(idx+1, currcap-w[idx]) + v[idx];
        vis[idx][currcap] = true;
        return dp[idx][currcap] = max(tomar, notomar);
    }
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> n >> W;
    v.resize(n);
    w.resize(n);
    f(i,0,n) cin >> w[i] >> v[i];

    memset(vis, false, sizeof(vis));

    cout << Play(0, W) << endl;

    return 0;
}
