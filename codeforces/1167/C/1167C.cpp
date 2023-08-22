/**
    @author: c4ts0up
    @url: https://vjudge.net/contest/575697#problem/D
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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = 5e5+5;
const ld DINF = 1e10, EPS = 1e-10;

ll n, m, x, y, z;
vector <ll> costos;

ll roots[NMAX];
ll h[NMAX];

ll find(ll x) {
    if (roots[x] == x) return x;
    else return roots[x] = find(roots[x]);
}

void unir(ll x, ll y) {
    ll Rx = find(x);
    ll Ry = find(y);

    if (Rx == Ry) return;

    if (h[Rx] < h[Ry]) roots[Rx] = Ry;
    else if (h[Rx] > h[Ry])  roots[Ry] = Rx;
    else {
        roots[Rx] = Ry;
        h[Ry]++;
    }
}

int main() {
    cin >> n >> m;

    for (int i=1; i<=n; i++) h[i] = 0, roots[i] = i;

    for (int i=0; i<m; i++) {
        cin >> z;
        vector <ll> elems;

        for (ll j=0; j<z; j++) {
            cin >> x;
            elems.pb(x);
        }

        for (ll j=1; j<z; j++) {
            unir(elems[j-1], elems[j]);
        }
    }

    unordered_map <ll, ll> componente;
    for (int i=1; i<=n; i++){
        ll r = find(i);
        //cerr << i << "(" << r << ")" << endl;
        if (!componente.count(r)) componente[r] = 1;
        else componente[r]++;
    }

    for (int i=1; i<=n; i++) cout << componente[find(i)] << " ";
    cout << endl;
    return 0;
}