/**
    @author: c4ts0up
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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = 205;

ll n, m, t, x, y;
vector <ll> Adj[NMAX];

int main() {
    #ifdef LOCAL
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    #endif
    fast_io();

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i=1; i<=n; i++) Adj[i].clear();

        for (int i=0; i<m; i++) {
            ll u, v;
            cin >> u >> v;
            Adj[u].pb(v);
            Adj[v].pb(u);
        }

        // empieza en un nodo hoja
        ll hoja = -1;
        for (ll i=1; i<=n; i++) {
            if (Adj[i].size() == 1) {
                hoja = i;
                break;
            }
        }

        // padre hoja
        ll padre_hoja = Adj[hoja][0], centro;

        y = Adj[padre_hoja].size()-1;

        // revisa los vecinos
        for (ll v : Adj[padre_hoja]) {
            if (Adj[v].size() != 1) centro = v;
        }

        x = Adj[centro].size();


        cout << x << " " << y << endl;
    }
    return 0;
}