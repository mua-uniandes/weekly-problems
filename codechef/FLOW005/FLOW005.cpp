/**
    @author: c4ts0up
    @language: C++
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

const ll INF = 1e18+5, MOD = 1e9+7, NMAX = -1;

ll t, n;
vector <ll> rs = {100, 50, 10, 5, 2, 1};

int main() {
    /*//
    freopen("entrada.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    //*/

    cin >> t;
    while (t--) {
        cin >> n;
        ll cuenta = 0, coc;

        for (int i=0; i<rs.size() && n; i++) {
            coc = n/rs[i];
            cuenta += coc;
            n -= coc*rs[i];
        }

        cout << cuenta << endl;
    }
    return 0;
}