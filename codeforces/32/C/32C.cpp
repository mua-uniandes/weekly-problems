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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = -1;

ll n, m, s;

int main() {
    #ifdef LOCAL
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    #endif
    fast_io();

    cin >> n >> m >> s;

    // el +1 incluye la casilla actual
    ll c = ((n-1)/s+1) * ((m-1)/s+1);
    ll np = ((n-1) % s)+1;
    ll mp = ((m-1) % s)+1;

    cout << c*np*mp << endl;

    return 0;
}