/**
    @author: c4ts0up
    @url:
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = 100+5, VMAX = NMAX*1000+5;

ll n, w;
vector <ll> wi, vi;
ll dp[NMAX][VMAX];
bool vis[NMAX][VMAX];


ll Play(ll idx, ll vact) {
    // caso base
    if (idx == 0) return (vact ? INF : 0LL);
    // caso dp
    else if (vis[idx][vact]) return dp[idx][vact];
    // caso recursivo
    else {
        ll notake = Play(idx-1, vact);
        ll take = INF;

        if (vact - vi[idx-1] >= 0) take = Play(idx-1, vact-vi[idx-1]) + wi[idx-1];

        vis[idx][vact] = true;
        return dp[idx][vact] = min(notake, take);
    }
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> n >> w;
    wi.resize(n);
    vi.resize(n);
    for (int i=0; i<n; i++) cin >> wi[i] >> vi[i];

    memset(vis, false, sizeof(vis));

    ll res = VMAX-1;
    for (;res>=0; res--) {
        if (Play(n, res) <= w) break;
    }

    cout << res << endl;
    return 0;
}