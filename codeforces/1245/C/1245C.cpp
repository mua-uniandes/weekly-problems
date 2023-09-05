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

const ll INF = 1e18+5, MOD = 1e9+7, TMAX = 1e5+5;

string cad;
ll tam, n;
ll dp[TMAX];
bool vis[TMAX];

ll Play(ll idx) {
    // caso base
    if (idx == 0) return 1LL;
    // caso dp
    else if (vis[idx]) return dp[idx];
    // caso recursivo
    else {
        ll nomix = Play(idx-1);
        ll mix = 0;

        if (idx-1 >= 0) mix = Play(idx-2);

        vis[idx] = true;
        return dp[idx] = mix + nomix;
    }
}


int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    cin >> cad;
    n = cad.size();
    memset(vis, false, sizeof(vis));

    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<TMAX; i++) dp[i] = (dp[i-1] + dp[i-2])%MOD;

    ll res = 1;
    for (ll i=0; i<n; i++) {
        // inválido
        if (cad[i] == 'm' || cad[i] == 'w') res = 0;
        else if (cad[i] == 'n' || cad[i] == 'u') {
            ll j=i;
            while (j<n && cad[j] == cad[i]) j++;
            tam = j-i;
            res = (res * dp[tam])%MOD;
            i = j-1;
        }
    }

    cout << res << endl;
    return 0;
}