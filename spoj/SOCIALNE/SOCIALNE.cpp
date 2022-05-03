/**
    @author: c4ts0up
    @language: 
    @task: 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define ff first
#define ss second
#define endl "\n"

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll MOD = 1e9+7, NMAX = 55, INF = 1e15;
ll t, n;
string cad;

bool Adj[NMAX][NMAX];

ll PF(ll u) {
    unordered_set <ll> seen;
    
    for (ll v=0; v<n; v++) {
        for (ll w=0; w<n; w++) {
            if (Adj[u][v] && Adj[v][w] && !Adj[u][w] && u != w) seen.insert(w);
        }
    }

    return seen.size();
}

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> cad;
        n = cad.length();

        for (int i=0; i<n; i++) {
            Adj[0][i] = (cad[i] == 'Y');
        }

        for (int i=1; i<n; i++) {
            cin >> cad;
            for (int j=0; j<n; j++) {
                Adj[i][j] = (cad[j] == 'Y');
            }
        }

        ll maxbf = -1, id = -1;

        for (int u=0; u<n; u++) {
            ll pf = PF(u);
            //cerr << u << " : " << pf << endl;

            if (pf > maxbf) {
                maxbf = pf;
                id = u;
            }
        }

        cout << id << " " << maxbf << endl;
    }
    return 0;
}