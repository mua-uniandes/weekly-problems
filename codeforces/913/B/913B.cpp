
/**
    @author: c4ts0up
    @task: MUA 2023-10 - 3B
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

const ll INF = 1e18 + 5, MOD = 1e9 + 7, NMAX = 1005;

int n;
vector <int> Adj[NMAX];
vector <bool> vis;
vector <int> padre, isleaf, leafch;

bool DFS(int u) {
    // lo visita
    vis[u] = true;
    // hoja
    if (Adj[u].size() == 0) return true;
    // tiene menos de 3 hijos
    else if (Adj[u].size() < 3) return false;

    bool res = true;
    // visita a los hijos
    for (int v : Adj[u]) {
        res = res && DFS(v);
    }

    return res;
}


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> n;

    padre.resize(n+1);
    isleaf.resize(n+1);
    leafch.resize(n+1);
    for (int i=1; i<=n; i++) padre[i] = -1, isleaf[i] = 1, leafch[i] = 0;

    for (int i=2; i<=n; i++) {
        int p;
        cin >> p;
        padre[i] = p;
        isleaf[p] = 0;
    }

    for (int i=1; i<=n; i++) {
        if (isleaf[i]) leafch[padre[i]]++;
    }

    bool spruce = true;
    for (int i=1; i<=n; i++) {
        if (isleaf[i] || leafch[i]>=3) continue;
        else spruce = false;
    }

    cout << (spruce ? "Yes" : "No") << endl;
}
