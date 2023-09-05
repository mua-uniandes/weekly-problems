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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = 35, BMAX = 8;

ll n;
ll dp[NMAX][BMAX];

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/
    fast_io();

    dp[0][0] = 0LL;
    dp[0][1] = 1LL;
    dp[0][2] = 0LL;
    dp[0][3] = 0LL;
    dp[0][4] = 1LL;
    dp[0][5] = 0LL;
    dp[0][6] = 0LL;
    dp[0][7] = 1LL;
    for (ll i=1; i<NMAX; i++) {
        dp[i][0] = dp[i-1][7] + dp[i-1][4] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + dp[i-1][6];
        dp[i][2] = dp[i-1][5];
        dp[i][3] = dp[i-1][4];
        dp[i][4] = dp[i-1][0] + dp[i-1][3];
        dp[i][5] = dp[i-1][2];
        dp[i][6] = dp[i-1][1];
        dp[i][7] = dp[i-1][0];
    }

    while (true) {
        cin >> n;
        if (n == -1LL) break;
        else if (n == 0) cout << 1 << endl;
        else cout << dp[n-1][0] << endl;
    }

    return 0;
}