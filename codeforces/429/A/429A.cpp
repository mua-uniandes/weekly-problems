
/**
    @author: c4ts0up
    @task: MUA 2023-10 - 3D
    @url: https://vjudge.net/contest/543264#problem/B
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define sort(a) sort(a.begin(), a.end())

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = 1e5+5;

int n;
vector <int> Adj[NMAX];
vector <bool> val, goal;
vector <bool> vis;
vector <int> changed;


void Traversal(int nodo, int prof, bool par, bool impar) {
    vis[nodo] = true;
    // par
    if (prof % 2 == 0) {
        bool cambio = (!val[nodo] != !par) != goal[nodo];
        if (cambio) changed.pb(nodo);
        for (int v : Adj[nodo]) {
            if (!vis[v]) Traversal(v, prof + 1, (!cambio != !par), impar);
        }
    }
    // impar
    else {
        bool cambio = (!val[nodo] != !impar) != goal[nodo];
        if (cambio) changed.pb(nodo);
        for (int v : Adj[nodo]) {
            if (!vis[v]) Traversal(v, prof + 1, par, (!cambio != !impar));
        }
    }
}


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u].pb(v);
        Adj[v].pb(u);
    }

    val.resize(n+1);
    vis.resize(n+1);
    goal.resize(n+1);
    for (int i=1; i<=n; i++) vis[i] = false;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        val[i] = (x == 1);
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        goal[i] = (x == 1);
    }

    Traversal(1, 0, false, false);
    cout << changed.size() << endl;
    for (int x : changed) {
        cout << x << endl;
    }
}
