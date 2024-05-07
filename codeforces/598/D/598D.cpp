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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = 1005;

ll n, m, k;
bool vis[NMAX][NMAX];
ll pics[NMAX][NMAX];
char grid[NMAX][NMAX];


void DFS(pll source) {
    stack <pll> to;
    vector <pll> seen;
    to.push(source);
    ll p = 0;

    while (!to.empty()) {
        pll u = to.top();
        to.pop();

        //cerr << "Visitando " << u.ff << ", " << u.ss << "(" << grid[u.ff][u.ss] << ")" << endl;

        // vistamos
        vis[u.ff][u.ss] = true;
        vector <ll> dx = {-1,0,0,1};
        vector <ll> dy = {0,-1,1,0};
        // vecinos
        for (int i=0; i<dx.size(); i++) {
            // es válido
            if (0 > u.ff + dx[i] || u.ff + dx[i] >= n) continue;
            else if (0 > u.ss + dy[i] || u.ss + dy[i] >= m) continue;

            // contar la pared
            if (grid[u.ff+dx[i]][u.ss+dy[i]] == '*') p++;

            // no está visitado
            if (!vis[u.ff + dx[i]][u.ss + dy[i]] && grid[u.ff+dx[i]][u.ss+dy[i]] == '.') {
                to.push({u.ff+dx[i], u.ss+dy[i]});
                vis[u.ff+dx[i]][u.ss+dy[i]] = true;
            }
        }

        seen.pb(u);
    }

    //cerr << "p = " << p << endl;
    for (pll u : seen) {
        pics[u.ff][u.ss] = p;
    }
}




int main() {
    #ifdef LOCAL
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    #endif
    fast_io();

    cin >> n >> m >> k;

    for (int i=0; i<n; i++) {
        string cad;
        cin >> cad;
        for (int j=0; j<m; j++) grid[i][j] = cad[j];
    }
    //cerr << "Reading ok ..." << endl;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') DFS({i,j});
        }
    }

    //cerr << "DFS ok ..." << endl;

    for (int i=0; i<k; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        cout << pics[x][y] << endl;
    }
    return 0;
}